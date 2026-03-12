#pragma once

#include "fallout_shared/bipedanim.h"
#include "fallout_shared/tesform.h"
#include "nimain/niavobject.h"
#include "nimain/ninpshortpoint3.h"

class TESObjectCELL;
class TESObjectList;
class TESObjectREFR;
class TESWaterForm;

class TESObject : public TESForm {
public:
    TESObject(const TESObject &);
    TESObject();
    virtual ~TESObject();
    virtual NiAVObject *Load3D();
    NiAVObject *Get3D();
    virtual unsigned int GetRefCount();
    TESObjectList *GetParentList();
    unsigned int GetModelCount();
    virtual bool IsObject();
    virtual bool IsBoundAnimObject();
    virtual TESWaterForm *GetWaterType();
    virtual char *GetObjectTypeName();
    virtual bool IsAutoCalc();
    virtual void SetAutoCalc(bool);
    virtual NiAVObject *Clone3D(TESObjectREFR *, bool);
    virtual void UnClone3D(TESObjectREFR *);
    virtual bool IsMarker();
    virtual bool IsOcclusionMarker();
    virtual void InitDefaultWorn();
    virtual bool ReplaceModel();
    virtual bool ReplaceModel(BipedAnim *);
    virtual void Set3D(NiAVObject *, bool);
    void SetParentList(TESObjectList *);
    virtual unsigned int IncRef();
    virtual unsigned int DecRef();
    void nod_SetPrev(TESObject *);
    void nod_SetNext(TESObject *);
    TESObject *nod_GetPrev();
    TESObject *nod_GetNext();
    const char *GetModelFileName(TESObjectREFR *);
    void GetScaledModelFileName(TESObjectREFR *, char *);
    void GetLODModelFileName(TESObjectREFR *, char *);
    void GetLODFlatFileName(TESObjectREFR *, char *);
    virtual NiAVObject *LoadGraphics(TESObjectREFR *);

    static NiAVObject *FindGeometryByName(NiAVObject *, const char *);

protected:
    TESObjectList *m_pParentList; // 0x28
    TESObject *nod_lpPrev; // 0x2c
    TESObject *nod_lpNext; // 0x30
};

class TESObjectList {
public:
    TESObjectList(bool);
    ~TESObjectList();
    TESObject *lnk_Add();
    TESObject *lnk_Insert(TESObject *);
    void lnk_Move(TESObject *, TESObject *);
    void lnk_Delete(TESObject *);
    void lnk_Destroy();
    void lnk_Remove(TESObject *);
    TESObject *lnk_Place(TESObject *, TESObject *);
    TESObject *lnk_Append(TESObject *);
    TESObject *lnk_GetNext(TESObject *);
    TESObject *lnk_GetPrev(TESObject *);
    unsigned int lnk_GetCount();
    TESObject *lnk_GetRoot();
    TESObject *lnk_GetTail();
    TESObjectCELL *GetOwner();
    void SetOwner(TESObjectCELL *);

protected:
    unsigned int lnk_dwCount; // 0x0
    TESObject *lnk_lpRoot; // 0x4
    TESObject *lnk_lpTail; // 0x8
    TESObjectCELL *pOwner; // 0xc
};

class TESBoundObject : public TESObject {
public:
    struct BOUND_DATA {
        NiNPShortPoint3 BoundMin; // 0
        NiNPShortPoint3 BoundMax; // 6

        void Endian();
    };

    TESBoundObject(const TESBoundObject &);
    TESBoundObject();
    virtual ~TESBoundObject();
    virtual bool IsBoundObject();
    void SetBoundMinMax(NiAVObject *);
    void CopyBoundData(TESBoundObject *);
    NiPoint3 GetBoundMin();
    NiPoint3 GetBoundMax();
    float GetBoundSize();
    virtual void SaveObjectBound();
    virtual void LoadObjectBound(TESFile *);
    virtual NiAVObject *Clone3D(TESObjectREFR *, bool);
    virtual NiAVObject *Clone3D(TESObjectREFR *);
    virtual bool ReplaceModel(const char *);
    virtual bool ReplaceModel();
    virtual bool Activate(TESObjectREFR *, TESObjectREFR *, bool, TESBoundObject *, int);
    bool GetLODObjectExists(bool);
    TESBoundObject &operator=(const TESBoundObject &);

    //   static void CalcBoundingBox(NiAVObject*, NiPoint3*, NiPoint3*, const NiPoint3&,
    //   const NiMatrix3&, const float&); static void
    //   CalcBoundingBoxRecursive(NiAVObject*, NiPoint3*, NiPoint3*, bool&, bool&, const
    //   NiPoint3&, const NiMatrix3&, const float&);

protected:
    BOUND_DATA BoundData; // 0x34
};

class TESBoundAnimObject : public TESBoundObject {
public:
    TESBoundAnimObject(const TESBoundAnimObject &);
    TESBoundAnimObject();
    virtual ~TESBoundAnimObject();
    virtual bool IsBoundAnimObject();
    virtual void Set3D(NiAVObject *, bool);
    virtual bool ReplaceModel(const char *);
    TESBoundAnimObject &operator=(const TESBoundAnimObject &);
};
