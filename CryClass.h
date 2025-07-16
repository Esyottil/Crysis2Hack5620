#include "Enums.h"
#include "vector3.hpp"

uintptr_t GameModuleAddress = 0;
class SSystemGlobalEnvironment;
class ISystem;
class IRenderer;
class IEntitySystem;
class CGame;
class IEntityIt;
class IEntity;
class IEntityProxy;
class IGameFramework;
class IActorSystem;
class IActor;
class IGameRules;
class IGameRulesSystem;
class ICharacterInstance;
class ISkeletonPose;
class I3DEngine;
class IPhysicalWorld;
class IPhysicalEntity;

class SSystemGlobalEnvironment 
{
public:
    IEntitySystem* GetIEntitySystem() {
        return *(IEntitySystem**)((uintptr_t)this + 0x38);
    }
    IRenderer* GetIRenderer() {
        return *(IRenderer**)((uintptr_t)this + 0x0C);
    }
    I3DEngine* GetI3DEngine() {
        return *(I3DEngine**)((uintptr_t)this + 0x20);
    }
    IPhysicalWorld* GetIPhysicalWorld() {
        return *(IPhysicalWorld**)((uintptr_t)this + 0x2C);
    }


    static SSystemGlobalEnvironment* Singleton() {
        uintptr_t SSGE = *(uintptr_t*)(GameModuleAddress + 0x6BC520);
        return reinterpret_cast<SSystemGlobalEnvironment*>(SSGE);
    }
};

class CGame
{
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
    virtual IGameFramework* GetIGameFramework();

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
    virtual void Function10(); // GetEntity
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual IEntityIt* GetEntityIterator(); //
};

class IRenderer
{
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
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
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
    virtual void Function58(); //
    virtual void Function59(); //
    virtual int GetWidth(); // 
    virtual int GetHeight(); // 
    virtual void Function62(); //
    virtual void Function63(); //
    virtual void Function64(); //
    virtual void Function65(); //
    virtual void Function66(); //
    virtual void Function67(); //
    virtual void Function68(); //
    virtual void Function69(); //
    virtual void Function70(); //
    virtual void Function71(); //
    virtual void Function72(); //
    virtual void Function73(); //
    virtual void Function74(); //
    virtual void Function75(); //
    virtual void ProjectToScreen(float ptx, float pty, float ptz, float* sx, float* sy, float* sz) = 0;

};

class I3DEngine
{
public:

};

struct ray_hit {
    float dist;
    IPhysicalEntity* pCollider;
    int ipart;
    int partid;
    int surface_idx;
    int idmatOrg;	// original material index, not mapped with material mapping
    int foreignIdx;
    int iNode; // BV tree node that had the intersection; can be used for "warm start" next time
    Vec3 pt;
    Vec3 n;	// surface normal
    int bTerrain;	// global terrain hit
    ray_hit* next; // reserved for internal use, do not change
};

struct ray_hit_cached {	// used in conjunction with rwi_reuse_last_hit
    ray_hit_cached() { pCollider = 0; ipart = 0; }
    ray_hit_cached(const ray_hit& hit) { pCollider = hit.pCollider; ipart = hit.ipart; iNode = hit.iNode; }
    ray_hit_cached& operator=(const ray_hit& hit) { pCollider = hit.pCollider; ipart = hit.ipart; iNode = hit.iNode; return *this; }

    IPhysicalEntity* pCollider;
    int ipart;
    int iNode;
};

struct SRWIParams
{

    void* pForeignData;
    int               iForeignData;
    int(__fastcall* OnEvent)(const void*);
    Vec3              org;
    Vec3              dir;
    int               objtypes;
    unsigned int      flags;
    ray_hit* hits;
    int               nMaxHits;
    ray_hit_cached* phitLast;
    int               nSkipEnts;
    IPhysicalEntity** pSkipEnts;
};

class IPhysicalWorld
{
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
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
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
    //virtual int RayWorldIntersection(Vec3 org, Vec3 dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts = 0, int nSkipEnts = 0, void* pForeignData = 0, int iForeignData = 0, const char* pNameTag = RWI_NAME_TAG, ray_hit_cached* phitLast = 0, int iCaller = 1) = 0;
    virtual int RayWorldIntersection(SRWIParams& rp, const char* pNameTag, int iCaller);

    int RayWorldIntersection(const Vec3& org, const Vec3& dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts = 0, int nSkipEnts = 0, void* pForeignData = 0, int iForeignData = 0, const char* pNameTag = "", ray_hit_cached* phitLast = 0, int iCaller = 4) {

        SRWIParams rp;
        memset(&rp, 0, sizeof SRWIParams);
        rp.org = org;
        rp.dir = dir;
        rp.objtypes = objtypes;
        rp.flags = flags;
        rp.hits = hits;
        rp.nMaxHits = nMaxHits;
        rp.pForeignData = pForeignData;
        rp.iForeignData = iForeignData;
        rp.phitLast = phitLast;
        rp.pSkipEnts = pSkipEnts;
        rp.nSkipEnts = nSkipEnts;

        return this->RayWorldIntersection(rp, pNameTag, iCaller);
    }

};

class IEntityIt {
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual IEntity* Next(); // 
};

class IEntity
{
public:
    virtual void Function0(); //
    virtual int GetId(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void SetFlags(unsigned int flags); //
    virtual unsigned int GetFlags(); //
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
    virtual const Matrix34& GetWorldTM() const = 0; //
    virtual void Function24(); //
    virtual void GetWorldBounds(AABB& bbox) = 0;
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
    virtual Quat GetWorldRotation() const = 0;
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
    virtual IEntityProxy* GetProxy(EEntityProxy proxy); // 58
    virtual void Function59(); //
    virtual void Function60(); //
    virtual void Function61(); //
    virtual void Function62(); //
    virtual void Function63(); //
    virtual void Function64(); //
    virtual void Function65(); //
    virtual void Function66(); //
    virtual void Function67(); //
    virtual void Function68(); //
    virtual void Function69(); //
    virtual void Function70(); //
    virtual void Function71(); //
    virtual void Function72(); //
    virtual void Function73(); //
    virtual void Function74(); //
    virtual void Function75(); //
    virtual void Function76(); //
    virtual void Function77(); //
    virtual void Function78(); //
    virtual void Function79(); //
    virtual void Function80(); //
    virtual ICharacterInstance* GetCharacter( int nSlot ) = 0; //81
};

class IEntityProxy
{
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
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12();//
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
    virtual void SetVisionParams(float r, float g, float b, float a);
};

class IGameFramework
{
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
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
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
    virtual IActorSystem* GetIActorSystem();
    virtual void Function26(); //
    virtual void Function27(); //
    virtual void Function28(); //
    virtual void Function29(); //
    virtual void Function30(); //
    virtual void Function31(); //
    virtual IGameRulesSystem* GetIGameRulesSystem(); //
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
    virtual void Function58(); //
    virtual void Function59(); //
    virtual void Function60(); //
    virtual void Function61(); //
    virtual void Function62(); //
    virtual void Function63(); //
    virtual void Function64(); //
    virtual void Function65(); //
    virtual void Function66(); //
    virtual void Function67(); //
    virtual void Function68(); //
    virtual void Function69(); //
    virtual void Function70(); //
    virtual IActor* GetClientActor();
};

class IActorSystem
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual IActor* GetActor(int entityId); //EntityId
};

class IActor
{
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
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
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
    virtual void SetHealth(float health); // 23
    virtual virtual float GetHealth(); // 24
    virtual void Function25(); //
    virtual void Function26(); //
    virtual void Function27(); //
    virtual void Function28(); //
    virtual void Function29(); //
    virtual void Function30(); //
    virtual bool IsDead();
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
    virtual void SetViewRotation(const Quat& rotation);

    IEntity* GetEntity()
    {
        return *(IEntity**)((uintptr_t)this + 0x000C);
    }

};

class IGameRulesSystem
{
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
    virtual IGameRules* GetCurrentGameRules(); //
};

class IGameRules
{
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
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
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
    virtual void Function58(); //
    virtual void Function59(); //
    virtual void Function60(); //
    virtual void Function61(); //
    virtual void Function62(); //
    virtual void Function63(); //
    virtual void Function64(); //
    virtual void Function65(); //
    virtual void Function66(); //
    virtual void Function67(); //
    virtual void Function68(); //
    virtual void Function69(); //
    virtual void Function70(); //
    virtual void Function71(); //
    virtual void Function72(); //
    virtual void Function73(); //
    virtual void Function74(); //
    virtual void Function75(); //
    virtual void Function76(); //
    virtual void Function77(); //
    virtual void Function78(); //
    virtual void Function79(); //
    virtual void Function80(); //
    virtual void Function81(); //
    virtual void Function82(); //
    virtual void Function83(); //
    virtual void Function84(); //
    virtual void Function85(); //
    virtual void Function86(); //
    virtual void Function87(); //
    virtual void Function88(); //
    virtual void Function89(); //
    virtual void Function90(); //
    virtual void Function91(); //
    virtual void Function92(); //
    virtual void Function93(); //
    virtual void Function94(); //
    virtual void Function95(); //
    virtual void Function96(); //
    virtual void Function97(); //
    virtual void Function98(); //
    virtual void Function99(); //
    virtual void Function100(); //
    virtual void Function101(); //
    virtual void Function102(); //
    virtual void Function103(); //
    virtual void Function104(); //
    virtual void Function105(); //
    virtual void Function106(); //
    virtual void Function107(); //
    virtual void Function108(); //
    virtual void Function109(); //
    virtual void Function110(); //
    virtual void Function111(); //
    virtual void Function112(); //
    virtual void Function113(); //
    virtual void Function114(); //
    virtual void Function115(); //
    virtual void Function116(); //
    virtual void Function117(); //
    virtual void Function118(); //
    virtual void Function119(); //
    virtual void Function120(); //
    virtual void Function121(); //
    virtual void Function122(); //
    virtual void Function123(); //
    virtual void Function124(); //
    virtual void Function125(); //
    virtual void Function126(); //
    virtual void Function127(); //
    virtual void Function128(); //
    virtual void Function129(); //
    virtual void Function130(); //
    virtual void Function131(); //
    virtual void Function132(); //
    virtual void Function133(); //
    virtual void Function134(); //
    virtual void Function135(); //
    virtual void Function136(); //
    virtual void Function137(); //
    virtual int GetTeam(int entityId); //
};

class ICharacterInstance
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual ISkeletonPose* GetISkeletonPose() = 0;
};

class ISkeletonPose
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual int16 GetJointIDByName(const char* szJointName) const = 0;
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual const QuatT& GetAbsJointByID(int32 nJointID) = 0;
};