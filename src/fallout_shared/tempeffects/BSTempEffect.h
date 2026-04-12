#pragma once

#include "bscore/bssimplelist.h"
#include "fallout/misc/saveload/BGSLoadGameBuffer.h"
#include "fallout/misc/saveload/bgssavegamebuffer.h"
#include "fallout_shared/teschildcell.h"
#include "nimain/NiNode.h"
#include "nimain/NiObject.h"

enum TEMP_EFFECT_TYPE {
    TEMP_EFFECT_DECAL = 0x0000,
    TEMP_EFFECT_GEOMETRY_DECAL = 0x0001,
    TEMP_EFFECT_PARTICLE = 0x0002,
    TEMP_EFFECT_DEFAULT = 0x0003,
    MAGIC_HIT_EFFECT_DEFAULT = 0x0004,
    MAGIC_HIT_EFFECT_MODEL = 0x0005,
    MAGIC_HIT_EFFECT_SHADER = 0x0006,
};

class BSTempEffect : public NiObject {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    bool IsExactKindOf(const NiRTTI *__restrict) const;
    bool IsKindOf(const NiRTTI *__restrict) const;
    virtual NiNode *IsNode();
    // virtual BSFadeNode *IsFadeNode();
    // virtual BSMultiBoundNode *IsMultiBoundNode();
    // virtual NiGeometry *IsGeometry();
    // virtual NiTriBasedGeom *IsTriBasedGeom();
    // virtual NiTriStrips *IsTriStrips();
    // virtual NiTriShape *IsTriShape();
    // virtual BSSegmentedTriShape *IsSegmentedTriShape();
    // virtual BSResizableTriShape *IsResizableTriShape();
    // virtual NiParticles *IsParticlesGeom();
    // virtual NiLines *IsLinesGeom();
    // virtual bhkNiCollisionObject *IsBhkNiCollisionObject();
    // virtual bhkBlendCollisionObject *IsBhkBlendCollisionObject();
    // virtual bhkRigidBody *IsBhkRigidBody() const;
    // virtual bhkLimitedHingeConstraint *IsBhkLimitedHingeConstraint();
    BSTempEffect *DynamicCast(const NiRTTI *__restrict) const;
    BSTempEffect(const BSTempEffect &);
    BSTempEffect(TESObjectCELL *, float);
    virtual ~BSTempEffect();
    virtual void Initialize();
    virtual void Detach();
    virtual bool Update(float);
    virtual NiAVObject *Get3D();
    float GetLifetime() const;
    float GetAge() const;
    TESObjectCELL *GetCell() const;
    void SetCell(TESObjectCELL *);
    virtual TEMP_EFFECT_TYPE GetType();
    virtual bool CheckShouldSave();
    virtual unsigned short GetSaveSize();
    virtual void SaveGame(BGSSaveGameBuffer *);
    virtual void SaveGame();
    virtual void LoadGame(BGSLoadGameBuffer *);
    virtual bool LoadGame();
    virtual void InitLoadGame(BGSLoadGameBuffer *);
    virtual void FinishLoadGame(BGSLoadGameBuffer *);
    virtual bool GetIsForegroundEffect();

    static bool IsExactKindOf(const NiRTTI *, const BSTempEffect *);
    static bool IsKindOf(const NiRTTI *, const BSTempEffect *);
    static BSTempEffect *DynamicCast(const NiRTTI *, const BSTempEffect *);
    static void RemoveDecalFromList(BSTempEffect *);
    static void RemoveAllDecals();

protected:
    static BSSimpleList<NiPointer<BSTempEffect> > kDecalList;
    static int iNumDecals;

    float fLifetime; // 0x08
    TESObjectCELL *pCell; // 0x0c
    float fAge; // 0x10
    bool bInitialized; // 0x14
};
