//Crysis 2 5620 DX9
#include <Windows.h>
#include "MinHook/MinHook.h"
#include <string>
#include <cstdint>
#include <iostream>
#include "CryClass.h"
#include <d3d9.h>
#include <d3d9types.h>
#include <d3dx9.h>
#include <stdio.h>


#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

uintptr_t SystemModuleAddress = 0;

// === Offsets ===
uintptr_t CSystemUpdate_Offset = 0x4B290;

// === Функции ===
typedef bool(__thiscall* SystemUpdateFn)(ISystem*, int, int);
typedef HRESULT(__stdcall* EndSceneFn)(IDirect3DDevice9*);
typedef HRESULT(__stdcall* ResetFn)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
typedef HRESULT(__stdcall* PresentFn)(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);

// === Оригиналы ===
SystemUpdateFn originalSystemUpdate;
EndSceneFn oEndScene = nullptr;
ResetFn oReset = nullptr;
PresentFn oPresent = nullptr;

IDirect3DDevice9* g_pDevice = nullptr;
ID3DXFont* g_pFont = nullptr;

void DrawTextF(int x, int y, DWORD color, const char* text, DWORD style)
{
    RECT rect;
    SetRect(&rect, x, y, x + 200, y + 20);
    if (g_pFont)
        g_pFont->DrawTextA(nullptr, text, -1, &rect, style, color);
}

bool WorldToScreen(Vec3 vEntPos, Vec3& vOut)
{
    SSystemGlobalEnvironment* m_SSystemGlobalEnvironment = SSystemGlobalEnvironment::Singleton();
    IRenderer* Renderer = m_SSystemGlobalEnvironment->GetIRenderer();

    Renderer->ProjectToScreen(vEntPos.x, vEntPos.y, vEntPos.z, &vOut.x, &vOut.y, &vOut.z);

    vOut.x *= (Renderer->GetWidth() / 100.0f);
    vOut.y *= (Renderer->GetHeight() / 100.0f);
    vOut.z *= 1.0f;

    return ((vOut.z < 1.0f) && (vOut.x > 0) && (vOut.x < (float)Renderer->GetWidth()) && (vOut.y > 0) && (vOut.y < (float)Renderer->GetHeight()));
}

Vec3 GetPlayerPos(IEntity* pEntit)
{
    Vec3 vOffset = Vec3();
    Matrix34 pWorld = pEntit->GetWorldTM();
    vOffset = pWorld.GetTranslation();
    return vOffset;
}

HRESULT __stdcall hkEndScene(IDirect3DDevice9* device)
{
    if (!g_pFont)
    {
        D3DXCreateFontA(device, 20, 0, FW_NORMAL, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &g_pFont);
    }

    const int startX = 10;
    const int startY = 10;
    const int lineHeight = 30;

    if (g_pFont)
    {
        SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::Singleton();
        if (!gEnv) return oEndScene(device);
        CGame* pGame = CGame::Singleton(); if(!pGame) return oEndScene(device);
        IGameFramework* pGameFramework = pGame->GetIGameFramework(); if (!pGameFramework) return oEndScene(device);

        IRenderer* pRenderer = gEnv->GetIRenderer();
        if (!pRenderer) return oEndScene(device);

        float ScreenCenterX = (pRenderer->GetWidth() / 2.0f);
        float ScreenCenterY = (pRenderer->GetHeight() / 2.0f);

        IEntitySystem* pEntitySystem = gEnv->GetIEntitySystem(); if(!pEntitySystem) return oEndScene(device);
        IEntityIt* pEntityIt = pEntitySystem->GetEntityIterator(); if(!pEntityIt) return oEndScene(device);
        while (IEntity* pEntity = pEntityIt->Next())
        {
            IActor* pActor = pGameFramework->GetIActorSystem()->GetActor(pEntity->GetId());
            if (pActor)
            {
                Vec3 PlayerPos = GetPlayerPos(pEntity);
                Vec3 PlayerPosOut;
                const char* playername = pEntity->GetName();
                if (WorldToScreen(PlayerPos, PlayerPosOut))
                {
                    DrawTextF(PlayerPosOut.x, PlayerPosOut.y, DarkYellow,playername, DT_CENTER);
                }
            }
        }

        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Crysis2_5620_Hack");
        DrawTextF(startX, startY + 0 * lineHeight, D3DCOLOR_XRGB(255, 255, 255), buffer, DT_LEFT);
        
        DrawTextF(ScreenCenterX, ScreenCenterY, DarkRed, "Center", DT_LEFT);
    }

    return oEndScene(device);
}

HRESULT __stdcall hkReset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    if (g_pFont)
    {
        g_pFont->Release();
        g_pFont = nullptr;
    }

    return oReset(device, pPresentationParameters);
}

void Feature()
{
    SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::Singleton();
    if (gEnv)
    {
        CGame* pGame = CGame::Singleton();
        if (pGame)
        {
            IGameFramework* pGameFramework = pGame->GetIGameFramework();
            if (pGameFramework)
            {
                IRenderer* pRenderer = gEnv->GetIRenderer(); if (!pRenderer) return;
                float ScreenCenterX = (pRenderer->GetWidth() / 2.0f);
                float ScreenCenterY = (pRenderer->GetHeight() / 2.0f);
                float ScreenBottomY = (pRenderer->GetHeight());


                IGameRulesSystem* pGameRulesSystem = pGameFramework->GetIGameRulesSystem(); if (!pGameRulesSystem) return;
                IGameRules* pGameRules = pGameRulesSystem->GetCurrentGameRules(); if (!pGameRules);

                IActor* m_pActor = pGameFramework->GetClientActor();
                if (m_pActor)
                {
                    IEntitySystem* pEntitySystem = gEnv->GetIEntitySystem();
                    if (pEntitySystem)
                    {
                        IEntityIt* pEntityit = pEntitySystem->GetEntityIterator();
                        if (pEntityit)
                        {
                            while (IEntity* pEntity = pEntityit->Next())
                            {
                                IEntityProxy* pEntityProxy = pEntity->GetProxy(ENTITY_PROXY_RENDER);
                                if (!pEntityProxy) continue;

                                IActor* pActor = pGameFramework->GetIActorSystem()->GetActor(pEntity->GetId());
                                if (pActor)
                                {
                                    //printf("[Actor]: %p | Name: %s | Healt: %.2f\n", pActor, pEntity->GetName(), pActor->GetHealth());
                                    pEntityProxy->SetVisionParams(255, 255, 0, 0);
                                    pEntity->SetFlags(ENTITY_FLAG_ON_RADAR);
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                        else
                        {
                            return;
                        }
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    return;
                }
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
}

bool __fastcall SystemUpdateHook(ISystem* mSystem, void* unk, int updateFlags, int nPauseMode)
{
    __asm pushad;
    Feature();
    __asm popad;

    return originalSystemUpdate(mSystem, updateFlags, nPauseMode);
}

HRESULT __stdcall hkPresent(IDirect3DDevice9* device, const RECT* src, const RECT* dest, HWND window, const RGNDATA* dirty_region)
{
    if (!g_pDevice)
    {
        g_pDevice = device;

        // Получаем адреса EndScene и Reset из vtable
        void** vTable = *reinterpret_cast<void***>(device);

        // Инициализируем MinHook
        MH_Initialize();

        // ==== Hook EndScene (обычно vtable[42]) ====
        void* pEndScene = vTable[42];
        MH_CreateHook(pEndScene, hkEndScene, reinterpret_cast<void**>(&oEndScene));
        MH_EnableHook(pEndScene);

        // ==== Hook Reset (обычно vtable[16]) ====
        void* pReset = vTable[16];
        MH_CreateHook(pReset, hkReset, reinterpret_cast<void**>(&oReset));
        MH_EnableHook(pReset);

        printf("[Hook] EndScene and Reset hooked successfully.\n");
    }

    return oPresent(device, src, dest, window, dirty_region);
}

void HookPresent()
{
    printf("[Hook] Starting hook Present...\n");

    IDirect3D9* d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (!d3d)
        return;

    D3DPRESENT_PARAMETERS pp = {};
    ZeroMemory(&pp, sizeof(pp));
    pp.Windowed = TRUE;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD;

    IDirect3DDevice9* device = nullptr;
    if (FAILED(d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GetDesktopWindow(),
        D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &device)))
    {
        d3d->Release();
        return;
    }

    void** vTable = *reinterpret_cast<void***>(device);
    void* pPresent = vTable[17]; // Present обычно находится на индексе 17

    MH_CreateHook(pPresent, hkPresent, reinterpret_cast<void**>(&oPresent));
    MH_EnableHook(pPresent);

    device->Release();
    d3d->Release();
}

bool InitializeHook()
{
    HMODULE hSystemModule = GetModuleHandleA("CrySystem.dll");
    if (!hSystemModule) {
        printf("Failed to get module handle for CrySystem.dll\n");
        return false;
    }

    HMODULE hGameModule = GetModuleHandleA("CryGameCrysis2.dll");
    if (!hGameModule) {
        printf("Failed to get module handle for CryGameCrysis2.dll\n");
        return false;
    }

    GameModuleAddress = (uintptr_t)hGameModule;

    uintptr_t funcAddr = (uintptr_t)hSystemModule + CSystemUpdate_Offset;

    if (MH_Initialize() != MH_OK)
    {
        return false;
    }

    HookPresent();

    if (MH_CreateHook((void*)funcAddr, SystemUpdateHook, reinterpret_cast<void**>(&originalSystemUpdate)) != MH_OK)
    {
        return false;
    }

    if (MH_EnableHook((void*)funcAddr) != MH_OK)
    {
        return false;
    }

    std::cout << "Successfully hooked CSystem::Update at 0x" << std::hex << funcAddr << std::dec << "\n";
    return true;
}



BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        AllocConsole();
        SetConsoleOutputCP(CP_UTF8);
        FILE* f;
        freopen_s(&f, "CONOUT$", "w", stdout);
        printf("DLL loaded.\n");

        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)InitializeHook, nullptr, 0, nullptr);
    }
    return TRUE;
}