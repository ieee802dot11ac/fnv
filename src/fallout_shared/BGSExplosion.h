#pragma once

#include "fallout_shared/BGSImpactDataSet.h"
#include "fallout_shared/BGSPreloadable.h"
#include "fallout_shared/BGSTextureSet.h"
#include "fallout_shared/TESEnchantableForm.h"
#include "fallout_shared/TESFullName.h"
#include "fallout_shared/TESImageSpaceModifiableForm.h"
#include "fallout_shared/tesmodel.h"
#include "fallout_shared/tesobject.h"
#include "fallout_shared/TESSound.h"

struct BGSExplosionData { /* Size=0x34 */
    float fForce; // 0x00
    float fDamage; // 0x04
    float fRadius; // 0x08
    TESObjectLIGH *pLight; // 0x0c
    TESSound *pSound1; // 0x10
    unsigned int iFlags; // 0x14
    float fImageSpaceRadius; // 0x18
    BGSImpactDataSet *pImpactDataSet; // 0x1c
    TESSound *pSound2; // 0x20
    float fRadiationRads; // 0x24
    float fRadiationDissipationTime; // 0x28
    float fRadiationRadius; // 0x2c
    SOUND_LEVEL eSoundLevel; // 0x30

    void Initialize();
    void Endian();
};

class BGSExplosion : public TESBoundObject,
                     public TESFullName,
                     public TESModel,
                     public TESEnchantableForm,
                     public BGSPreloadable,
                     public TESImageSpaceModifiableForm {
public:
    enum BGSExplosionFlags {
        RADIUS_IN_BSUNITS = 0x0001,
        USE_WORLD_ORIENTATION = 0x0002,
        KNOCKS_DOWN_ACTORS_ALWAYS = 0x0004,
        KNOCKS_DOWN_ACTORS_FORMULA = 0x0008,
        IGNORE_LOS = 0x0010,
        PUSH_EXPLODED_REF_ONLY = 0x0020,
        IGNORE_ISSWAP = 0x0040,
    };

    BGSExplosion();
    virtual ~BGSExplosion();
    BGSExplosionData *GetData();
    virtual void InitializeData();
    virtual bool Load(TESFile *);
    virtual void Save();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void InitItem();
    virtual NiAVObject *Clone3D(TESObjectREFR *, bool);
    virtual void UnClone3D(TESObjectREFR *);
    float GetForce();
    float GetDamage();
    float GetRadius();
    float GetRadiationRads();
    float GetRadiationDissipationTime();
    float GetRadiationRadius();
    TESObjectLIGH *GetLight();
    TESSound *GetSound1();
    TESSound *GetSound2();
    float GetImageSpaceRadius();
    float GetRadiusBSUnits();
    float GetRadiusFeet();
    float GetImageSpaceRadiusBSUnits();
    float GetImageSpaceRadiusFeet();
    float GetRadiationRadiusBSUnits();
    float GetRadiationRadiusFeet();
    BGSImpactDataSet *GetImpactDataSet();
    SOUND_LEVEL GetSoundLevel();
    int GetSoundLevelValue();
    void SetForce(float);
    void SetDamage(float);
    void SetRadiationRads(float);
    void SetRadiationDissipationTime(float);
    void SetLight(TESObjectLIGH *);
    void SetSound1(TESSound *);
    void SetSound2(TESSound *);
    void SetRadiusBSUnits(float);
    void SetRadiusFeet(float);
    void SetImageSpaceRadiusBSUnits(float);
    void SetImageSpaceRadiusFeet(float);
    void SetRadiationRadiusBSUnits(float);
    void SetRadiationRadiusFeet(float);
    void SetImpactDataSet(BGSImpactDataSet *);
    void SetSoundLevel(int);
    bool IsFlagSet(BGSExplosionFlags);
    void SetFlag(BGSExplosionFlags, bool);
    BGSTextureSet *GetDecalTextureSet(MATERIAL_TYPE);
    BGSImpactData *GetImpactData(MATERIAL_TYPE);
    TESBoundObject *QImpactPlacedObject();
    void SetImpactPlacedObject(TESBoundObject *);
    virtual void QueueFiles(IO_TASK_PRIORITY, QueuedFile *);
    void TestHavokLayer();

private:
    TESBoundObject *pImpactPlacedObject; // 0x80
    BGSExplosionData Data; // 0x84
};
