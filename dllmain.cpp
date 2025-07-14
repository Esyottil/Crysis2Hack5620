//Crysis 2 5620 DX9
#include <Windows.h>
#include "MinHook/MinHook.h"
#include <string>
#include <cstdint>
#include <iostream>
#include "CryClass.h"

uintptr_t SystemModuleAddress = 0;

// === Offsets ===
uintptr_t CSystemUpdate_Offset = 0x4B290;

// === Функции ===
typedef bool(__thiscall* SystemUpdateFn)(ISystem*, int, int);

// === Оригиналы ===
SystemUpdateFn originalSystemUpdate;

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
                                IActor* pActor = pGameFramework->GetIActorSystem()->GetActor(pEntity->GetId());
                                if (pActor)
                                {
                                    printf("[Actor]: %p | Name: %s | Healt: %.2f\n", pActor, pEntity->GetName(), pActor->GetHealth());
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