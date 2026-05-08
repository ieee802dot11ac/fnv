#pragma once

#include "fallout_shared/BGSTextureSet.h"
#include "fallout_shared/tesmodel.h"

struct TEX_SWAP {
    BGSTextureSet *pNewTexture; // 0x0
    int iGeomIndex; // 0x4
    char pGeomName[128]; // 0x8
};

struct TS_GEOM_DATA {
    char pGeomName[128]; // 0x00
    int iGeomIndex; // 0x80
};

class TESModelTextureSwap : public TESModel {
public:
    BSSimpleList<TEX_SWAP *> TextureSwapList; // 0x18

    TESModelTextureSwap(const TESModelTextureSwap &);
    TESModelTextureSwap();
    virtual ~TESModelTextureSwap();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    void Save(CHUNK_ID, CHUNK_ID, CHUNK_ID);
    bool BuildTextureSwapChunkData(void *&, unsigned int &);
    bool UnpackTextureSwapChunkData(void *, unsigned int, unsigned int);
    void InitItem(TESForm *);
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    BSSimpleList<TEX_SWAP *> *GetTexSwapList();
    TEX_SWAP *GetTexSwap(int);
    void ClearTexSwapList();
    void AddTexSwap(const char *, int, BGSTextureSet *);
    void RemoveTexSwap(int);
    void SwapTextures(NiAVObject *);
    virtual TESModelTextureSwap *GetAsModelTextureSwap();

    static void LoadModelTextureSwapChunk(TESModelTextureSwap *, TESFile *);
    static int FindGeometryIndexRecurse(NiAVObject *, const NiFixedString &);
    static bool SwapTexturesRecurse(NiAVObject *, BSMap<int, TEX_SWAP *> *, int &);
    static void FillTexSwapNameList(NiAVObject *, BSSimpleList<TS_GEOM_DATA *> *, int &);
    static bool HasTextureSwap(TESForm *, TESObjectREFR *);
};
