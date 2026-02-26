#pragma once

#include <types.h>
#include <bscore/newoverloads.h>

// new vegas hack
#define SPEEDTREE_MALLOC(x, line) ourMalloc(x, __FILE__, line, __FUNCTION__)
#define SPEEDTREE_FREE(x) ourFree(x)

#ifndef SPEEDTREE_MALLOC
#define SPEEDTREE_MALLOC malloc
#endif

#ifndef SPEEDTREE_FREE
#define SPEEDTREE_FREE free
#endif

class CSpeedTreeRT {
public:
    enum EWindMethod {
        WIND_GPU = 0,
        WIND_CPU,
        WIND_NONE,
    };
    enum ELodMethod {
        LOD_POP = 0, // 0x0000
        LOD_SMOOTH = 1, // 0x0001
        LOD_NONE = 3, // 0x0003
    };
    enum ELightingMethod {
        LIGHT_DYNAMIC = 0,
        LIGHT_STATIC,
    };
    enum EStaticLightingStyle {
        SLS_BASIC = 0,
        SLS_USE_LIGHT_SOURCES,
        SLS_SIMULATE_SHADOWS,
    };
    enum ECollisionObjectType {
        CO_SPHERE = 0,
        CO_CYLINDER,
        CO_BOX,
    };
    struct SGeometry;
    struct STextures;

private:
    CSpeedTreeRT(CSpeedTreeRT const *);

public:
    CSpeedTreeRT();
    ~CSpeedTreeRT();
    bool Compute(const float *, u32, bool);
    CSpeedTreeRT *Clone(float, float, float, u32) const;
    CSpeedTreeRT const *InstanceOf() const;
    CSpeedTreeRT *MakeInstance();
    void DeleteTransientData();
    bool LoadTree(unsigned char const *, u32);
    bool LoadTree(char const *);
    unsigned char *SaveTree(u32 &, bool) const;
    void GetTreeSize(float &, float &) const;
    void SetTreeSize(float, float);
    u32 GetSeed() const;
    const float *GetTreePosition() const;
    void SetTreePosition(float, float, float);
    void SetLeafTargetAlphaMask(unsigned char);
    CSpeedTreeRT::ELightingMethod GetBranchLightingMethod() const;
    void SetBranchLightingMethod(CSpeedTreeRT::ELightingMethod);
    CSpeedTreeRT::ELightingMethod GetLeafLightingMethod() const;
    void SetLeafLightingMethod(CSpeedTreeRT::ELightingMethod);
    CSpeedTreeRT::ELightingMethod GetFrondLightingMethod() const;
    void SetFrondLightingMethod(CSpeedTreeRT::ELightingMethod);
    CSpeedTreeRT::EStaticLightingStyle GetStaticLightingStyle() const;
    void SetStaticLightingStyle(CSpeedTreeRT::EStaticLightingStyle);
    float GetLeafLightingAdjustment() const;
    void SetLeafLightingAdjustment(float);
    static bool GetLightState(u32);
    static void SetLightState(u32, bool);
    static const float *GetLightAttributes(u32);
    static void SetLightAttributes(u32, const float *);
    const float *GetBranchMaterial() const;
    void SetBranchMaterial(const float *);
    const float *GetLeafMaterial() const;
    void SetLeafMaterial(const float *);
    const float *GetFrondMaterial() const;
    void SetFrondMaterial(const float *);
    static void GetCamera(float *, float *);
    static void SetCamera(const float *, const float *);
    static void SetTime(float);
    void ComputeWindEffects(bool, bool, bool);
    void ResetLeafWindState();
    bool GetLeafRockingState() const;
    void SetLeafRockingState(bool);
    void SetNumLeafRockingGroups(u32);
    bool HasComputed() const;
    float GetBranchDimmingScalar() const;
    void SetBranchDimmingScalar(float);
    float GetLeafDimmingScalar() const;
    void SetLeafDimmingScalar(float);
    float GetTrunkWidth() const;
    float GetTrunkLength() const;
    float GetMinimumBudAngle();
    void SetMinimumBudAngle(float);
    float GetMaximumBudAngle();
    void SetMaximumBudAngle(float);
    CSpeedTreeRT::ELodMethod GetLeafLodMethod() const;
    void SetLeafLodMethod(CSpeedTreeRT::ELodMethod);
    // CWindEngine *GetWindEngine() const;
    CSpeedTreeRT::EWindMethod GetLeafWindMethod() const;
    void SetLeafWindMethod(CSpeedTreeRT::EWindMethod);
    CSpeedTreeRT::EWindMethod GetBranchWindMethod() const;
    void SetBranchWindMethod(CSpeedTreeRT::EWindMethod);
    CSpeedTreeRT::EWindMethod GetFrondWindMethod() const;
    void SetFrondWindMethod(CSpeedTreeRT::EWindMethod);
    float GetWindStrength() const;
    float SetWindStrength(float, float, float);
    void SetWindStrengthAndLeafAngles(float, const float *, const float *, u32);
    static void SetNumWindMatrices(s32);
    static void SetWindMatrix(u32, const float *);
    void GetLocalMatrices(u32 &, u32 &);
    void SetLocalMatrices(u32, u32);
    void ComputeLodLevel();
    float GetLodLevel() const;
    void SetLodLevel(float);
    static void SetDropToBillboard(bool);
    unsigned short GetNum360Billboards() const;
    void SetNum360Billboards(unsigned short);
    bool GetHorizontalBillboard() const;
    void SetHorizontalBillboard(bool);
    void GetLodLimits(float &, float &) const;
    void SetLodLimits(float, float);
    short GetDiscreteBranchLodLevel(float) const;
    unsigned short GetDiscreteLeafLodLevel(float) const;
    short GetDiscreteFrondLodLevel(float) const;
    unsigned short GetNumBranchLodLevels() const;
    unsigned short GetNumLeafLodLevels() const;
    unsigned short GetNumFrondLodLevels() const;
    static void SetHorzBillboardFadeAngles(float, float);
    static void GetHorzBillboardFadeAngles(float &, float &);
    void FreeBranchColors();
    void FreeBranchWindData();
    void FreeProjectedShadowData();
    void FreeLeafLODDataArrays();
    void DeleteBranchGeometry();
    void DeleteFrondGeometry();
    unsigned char *GetFrondGeometryMapIndexes(s32) const;
    const float *GetLeafBillboardTable(u32 &) const;
    const float *GetLeafLodSizeAdjustments();
    void GetGeometry(CSpeedTreeRT::SGeometry &, unsigned long, short, short, short);
    void GetBSGeometryLODData(CSpeedTreeRT::SGeometry &, float);
    void GetTextures(CSpeedTreeRT::STextures &) const;
    void SetLeafTextureCoords(u32, const float *);
    void SetFrondTextureCoords(u32, const float *);
    static bool GetTextureFlip();
    static void SetTextureFlip(bool);
    void SetBranchTextureFilename(char const *);
    void SetLeafTextureFilename(u32, char const *);
    void SetFrondTextureFilename(u32, char const *);
    static void Authorize(char const *);
    static bool IsAuthorized();
    static char const *GetCurrentError();
    static void ResetError();
    void GetBoundingBox(float *) const;
    u32 GetLeafTriangleCount(float) const;
    u32 GetBranchTriangleCount(float) const;
    u32 GetFrondTriangleCount(float) const;
    u32 GetCollisionObjectCount();
    void GetCollisionObject(u32, CSpeedTreeRT::ECollisionObjectType &, float *, float *);
    char const *GetUserData() const;

private:
    void ComputeLeafStaticLighting();
    void ComputeSelfShadowTexCoords();
    static void NotifyAllTreesOfEvent(s32);
    static void SetError(char const *);
    // void ParseLodInfo(CTreeFileAccess *);
    // void ParseWindInfo(CTreeFileAccess *);
    // void ParseTextureCoordInfo(CTreeFileAccess *);
    // void ParseCollisionObjects(CTreeFileAccess *);
    // void SaveTextureCoords(CTreeFileAccess *) const;
    // void SaveCollisionObjects(CTreeFileAccess *) const;
    // void ParseShadowProjectionInfo(CTreeFileAccess *);
    // void SaveUserData(CTreeFileAccess *) const;
    // void ParseUserData(CTreeFileAccess *);
    // void SaveSupplementalTexCoordInfo(CTreeFileAccess *) const;
    // void ParseSupplementalTexCoordInfo(CTreeFileAccess *);
    static char *CopyUserData(char const *);
    void GetBranchGeometry(CSpeedTreeRT::SGeometry &, short);
    void GetFrondGeometry(CSpeedTreeRT::SGeometry &, short);
    void GetLeafGeometry(CSpeedTreeRT::SGeometry &, short);
    void Get360BillboardGeometry(CSpeedTreeRT::SGeometry &, unsigned long);
    void GetSimpleBillboardGeometry(CSpeedTreeRT::SGeometry &);
    static void
    GetTransitionValues(float, unsigned short, float, float, float, float, float &, float &, short &, short &);
    void SetupHorizontalBillboard();
    // CTreeEngine *m_pEngine; // 0x0
    // CIndexedGeometry *m_pBranchGeometry; // 0x4
    // CLeafGeometry *m_pLeafGeometry; // 0x8
    // CLightingEngine *m_pLightingEngine; // 0xC
    // CWindEngine *m_pWindEngine; // 0x10
    // CSimpleBillboard *m_pSimpleBillboard; // 0x14
    CSpeedTreeRT::ELodMethod m_eLeafLodMethod; // 0x18
    float m_fLeafLodTransitionRadius; // 0x1C
    float m_fLeafLodCurveExponent; // 0x20
    float m_fLeafSizeIncreaseFactor; // 0x24
    float m_fLeafTransitionFactor; // 0x28
    float *m_pLeafLodSizeFactors; // 0x2C
    u32 *m_pInstanceRefCount; // 0x30
    // STreeInstanceData *m_pInstanceData; // 0x34
    // SInstanceList *m_pInstanceList; // 0x38
    s32 m_nFrondLevel; // 0x3C
    float *m_pTreeSizes; // 0x40
    unsigned char m_ucTargetAlphaValue; // 0x44
    bool m_bTreeComputed; // 0x45
    s32 m_nBranchWindLevel; // 0x48
    // SEmbeddedTexCoords *m_pEmbeddedTexCoords; // 0x4C
    // CProjectedShadow *m_pProjectedShadow; // 0x50
    unsigned short m_usNum360Billboards; // 0x54
    // SCollisionObjects *m_pCollisionObjects; // 0x58
    // CFrondEngine *m_pFrondEngine; // 0x5C
    // CIndexedGeometry *m_pFrondGeometry; // 0x60
    unsigned short m_usNumFrondLodLevels; // 0x64
    char *m_pUserData; // 0x68
    bool m_b360Billboard; // 0x6C
    bool m_bHorizontalBillboard; // 0x6D
    float m_afHorizontalCoords[12]; // 0x70
    static u32 m_uiAllRefCount;
    static bool m_bTextureFlip;
    static bool m_bDropToBillboard;
    static float m_fHorizontalFadeStartAngle;
    static float m_fHorizontalFadeEndAngle;
    static float m_fHorizontalFadeValue;
};
