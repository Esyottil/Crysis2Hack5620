#include "Enums.h"
uintptr_t GameModuleAddress = 0;
class SSystemGlobalEnvironment;
class ISystem;
class IEntitySystem;
class CGame;
class IEntityIt;
class IEntity;
class IEntityProxy;
class IGameFramework;
class IActorSystem;

class SSystemGlobalEnvironment 
{
public:
    IEntitySystem* GetIEntitySystem() {
        return *(IEntitySystem**)((uintptr_t)this + 0x38); // IEntitySystemPtr == 0x38
    }

    static SSystemGlobalEnvironment* Singleton() {
        // Адрес: GameModuleAddress + SSystemGlobalEnvironmentPtr (0x6BC520)
        uintptr_t SSGE = *(uintptr_t*)(GameModuleAddress + 0x6BC520);
        return reinterpret_cast<SSystemGlobalEnvironment*>(SSGE);
    }
};

class CGame
{
public:

    static CGame* Singleton()
    {
        uintptr_t pGame = *(uintptr_t*)(GameModuleAddress + 0x6C4D08);
        return reinterpret_cast<CGame*>(pGame);
    }
};

class IEntitySystem {
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //GetEntity
    virtual void Function11(); //FindEntityByName
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual IEntityIt* GetEntityIterator(); //
};

class IEntityIt {
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual IEntity* Next(); // 4
};

class IEntity
{
public:
    virtual void Function0(); //
    virtual int GetId(); //EntityId GetId() || 1 vfunc
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual const char* GetName();//
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual void Function18(); //
    virtual void Function19(); //
    virtual void Function20(); //
    virtual void Function21(); // 
    virtual void Function22(); //
    virtual void Function23(); //
    virtual void Function24(); //
    virtual void Function25(); //
    virtual void Function26(); //
    virtual void Function27(); //
    virtual void Function28(); //
    virtual void Function29(); //
    virtual void Function30(); //
    virtual void Function31(); //
    virtual void Function32(); //
    virtual void Function33(); //
    virtual void Function34(); //
    virtual void Function35(); //
    virtual void Function36(); //
    virtual void Function37(); //
    virtual void Function38(); //
    virtual void Function39(); //
    virtual void Function40(); //
    virtual void Function41(); //
    virtual void Function42(); //
    virtual void Function43(); //
    virtual void Function44(); //
    virtual void Function45(); //
    virtual void Function46(); //
    virtual void Function47(); //
    virtual void Function48(); //
    virtual void Function49(); //
    virtual void Function50(); //
    virtual void Function51(); //
    virtual void Function52(); //
    virtual void Function53(); //
    virtual void Function54(); //
    virtual void Function55(); //
    virtual void Function56(); //
    virtual void Function57(); //
    virtual IEntityProxy* GetProxy(EEntityProxy proxy);
};

class IEntityProxy
{
public:

};

class IGameFramework
{
public:
    //IGameFramework + 25 = IActorSystem
};

class IActorSystem
{
    // GetIActorSystem + 3 = GetActor
};

