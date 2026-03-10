#pragma once

#include "fallout_shared/tesform.h"
#include "nimain/niavobject.h"
#include "nimain/ninode.h"

class TESAmmo;
class TESObjectARMO;
class TESObjectCLOT;
class TESObjectLIGH;
class TESObjectREFR;
class TESObjectWEAP;

struct BIPBONE {
    unsigned char cFlags; // 0x0
    NiNode *pParent; // 0x4
};

struct BIPOBJECT {
    TESForm *pParent; // 0x0
    TESModel *pPart; // 0x4
    NiAVObject *pPartClone; // 0x8
    bool bSkinned; // 0xc
};

class BipedAnim {
public:
    BipedAnim(TESObjectREFR *, NiNode *);
    ~BipedAnim();
    void InitRoot(NiNode *);
    NiNode *GetRoot();
    void RemoveClothingAndArmor();
    void RemoveAllParts();
    void RemovePart(TESForm *);
    void RemovePart(BIPED_OBJECT, bool, int);
    void RemovePart(BIPOBJECT *, bool, int);
    void RecursivelyRemoveAllDecalPlacementVectorDataFromWeaponBone(NiAVObject *);
    NiNode *GetParentBone(BIPED_BONE);
    TESForm *GetParent(BIPED_OBJECT);
    TESForm *FindPart(NiAVObject *);
    bool FindObject(TESForm *);
    BIPOBJECT *FindBipObject(TESForm *);
    BIPOBJECT *GetBipObject(BIPED_OBJECT);
    void InitNaked(TESRace *, SEX);
    void SetBipedPart(TESForm *, TESModel *, BIPED_OBJECT);
    void LoadBipedParts(bool);
    void QueueBipedParts(IO_TASK_PRIORITY, NiPointer<QueuedHelmet> &, QueuedFile *);
    void QueueSkinTextures(unsigned int, IO_TASK_PRIORITY, QueuedFile *);
    void QueueSkinTexture(TESNPC *, BIPED_OBJECT, IO_TASK_PRIORITY, QueuedFile *);
    BIPOBJECT *QBufferedObjects();
    void SetBipedWeapon(TESObjectWEAP *, unsigned char);
    void AttachBipedWeapon(TESObjectWEAP *, unsigned char);
    void RemoveBipedWeapon();
    TESObjectWEAP *GetBipedWeapon();
    void AddWeaponOffset(float);
    void SetBipedAmmo(TESAmmo *);
    void AttachBipedAmmo(TESAmmo *);
    void RemoveBipedAmmo();
    void AttachBipedShield(TESObjectARMO *);
    void RemoveBipedShield();
    void AttachBipedRing(TESObjectCLOT *, bool);
    void RemoveBipedRing(bool);
    void AttachBipedAmulet(TESObjectCLOT *);
    void RemoveBipedAmulet();
    void SetBipedTorch(TESObjectLIGH *);
    void AttachBipedTorch(TESObjectLIGH *);
    void RemoveBipedTorch();
    TESObjectLIGH *GetBipedTorch();
    NiNode *GetBipedTorchClone();
    BSFaceGenModel *LoadFaceGenModel(BIPED_OBJECT);
    void QueueHelmetLoad(
        IO_TASK_PRIORITY, QueuedFile *, NiPointer<QueuedHelmet> &, BIPED_OBJECT
    );
    void QueueHelmetLoad(IO_TASK_PRIORITY, QueuedFile *, BIPED_OBJECT);
    NiNode *CloneHelmet(BSFaceGenModel *, NiNode *, BIPED_OBJECT);
    void AttachHelmet(BSFaceGenModel *, NiNode *, BIPED_OBJECT);
    TESObjectREFR *GetRequester();
    bool IsFaceGenObject(BIPED_OBJECT);

    static void RunBiped3DDetach(NiAVObject *);
    static void RecursiveWeaponOffset(NiNode *, float);
    static void AttachToSkeleton(NiNode *, NiAVObject *, NiNode *, bool);
    static void AttachToParent(
        NiNode *, NiNode *, NiNode *, BipedAnim *, BIPED_OBJECT, BSFaceGenModel *
    );
    static NiAVObject *
    LoadAndAttachAddOn(TESForm *, TESModel *, BIPED_OBJECT, TESObjectREFR *, NiAVObject *);
    static void AddAddonNodes(NiNode *, NiNode *, BIPED_OBJECT, TESObjectREFR *);
    // static BSShaderPPLightingProperty *GetLightingProperty(NiAVObject *);
    // static BIPED_OBJECT GetSkinBipedObject(NiAVObject *, BSShaderPPLightingProperty *);
    static unsigned int GetSkinModelFlags(NiAVObject *);

protected:
    NiAVObject *ApplySkinnedObjects(NiNode *, BIPED_OBJECT, bool, bool, BSFaceGenModel *);
    NiAVObject *
    AttachSkinnedObject(NiNode *, NiNode *, BIPED_OBJECT, bool, bool, BSFaceGenModel *);
    void AdjustSkinComplexion(NiAVObject *, bool);
    bool GetSlotHidden(BIPED_OBJECT);
    bool Get1stPersonModelFileName(TESModel *, char *);
    TESModel *Store1stPersonModel(BIPED_OBJECT, char *);
    TESModel *Get1stPersonModel(BIPED_OBJECT, TESModel *);

private:
    NiNode *root; // 0x0000
    BIPBONE bone[5]; // 0x0004
    BIPOBJECT object[20]; // 0x002c
    BIPOBJECT bufferedObjects[20]; // 0x016c
    float m_fWeaponOffset; // 0x02ac
    TESObjectREFR *m_pRequester; // 0x02b0
};
