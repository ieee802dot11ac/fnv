#pragma once

#include "fallout_shared/teschildcell.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/testexture.h"
#include "nimain/NiPoint2.h"
#include "nimain/NiTMap.h"
#include "nimain/NiTPointerMap.h"

class TESWorldSpace : public TESForm, public TESFullName, public TESTexture {
public:
    struct OFFSET_DATA {
        uint *pCellFileOffsets; // 0x00
        NiPoint2 OffsetMinCoords; // 0x04
        NiPoint2 OffsetMaxCoords; // 0x0c
        uint iFileOffset; // 0x14
    };

    TESWorldSpace(const TESWorldSpace &);
    TESWorldSpace();
    virtual ~TESWorldSpace();
    virtual void InitializeData();
    virtual void ClearData();
    virtual TESForm *CreateDuplicateForm(bool, NiTPointerMap<TESForm *, TESForm *> *);
    virtual bool Load(TESFile *);
    virtual bool LoadPartial(TESFile *);
    virtual void Save();
    virtual void InitItem();
    virtual bool SavesBefore(FORM *);
    virtual bool SavesBefore(TESForm *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    bool FindCellInFile(TESFile *, int, int);
    int GetIndexForCellCoord(TESFile *, int, int);
    void AdjustCellOffsets(TESFile *, int);
    virtual bool FindInFileFast(TESFile *);
    TESObjectCELL *LoadCell(int, int);
    void UnLoadCell(TESObjectCELL *);
    bool GetExtCellDataFromFileByEditorID(const char *, int &, int &);
    bool FindLandDataInFile(int, int, TESFile *&, uint &);
    float GetMinimumXCoord();
    float GetMinimumYCoord();
    float GetMaximumXCoord();
    float GetMaximumYCoord();
    TESClimate *GetClimate();
    void SetClimate(TESClimate *);
    TESImageSpace *GetImageSpace();
    TESImageSpace *GetUsableImageSpace();
    void SetImageSpace(TESImageSpace *);
    TESTerrainLODManager *GetTerrainLODManager();
    BGSTerrainManager *GetTerrainManager();
    bool GetSmallWorld();
    void SetSmallWorld(bool);
    bool CantTravelFrom();
    void SetCantTravelFrom(bool);
    bool GetCantWaitHere();
    void SetCantWaitHere(bool);
    bool GetHasBorderRegion();
    void SetHasBorderRegion(bool);
    bool GetNoLODWater();
    void SetNoLODWater(bool);
    bool GetNoLODNoise();
    void SetNoLODNoise(bool);
    bool GetWaterAdjustment();
    void SetWaterAdjustment(bool);
    bool AllowsNPCFallDamage();
    void SetAllowsNPCFallDamage(bool);
    float GetDefaultLandHeight();
    void SetDefaultLandHeight(float);
    float GetDefaultWaterHeight();
    void SetDefaultWaterHeight(float);
    BGSEncounterZone *GetEncounterZone();
    void SetEncounterZone(BGSEncounterZone *);
    const char *GetCanopyShadowTextureName();
    const char *GetWaterNoiseTextureName();
    void SetParentUseFlag(TESWorldSpace::PARENT_USE_FLAG, bool);
    bool GetParentUseFlag(TESWorldSpace::PARENT_USE_FLAG);
    TESWorldSpace *GetParentWorld(TESWorldSpace::PARENT_USE_FLAG);
    TESWorldSpace *GetParentWorldSimple();
    void SetParentWorld(TESWorldSpace *);
    WORLD_MAP_DATA *GetWorldMapData();
    const char *GetWorldMapTextureName();
    float GetWorldMapScale();
    void SetWorldMapScale(float);
    float GetWorldMapOffsetX();
    void SetWorldMapOffsetX(float);
    float GetWorldMapOffsetY();
    void SetWorldMapOffsetY(float);
    void AdjustMapMarkerCoord(NiPoint3 &, bool);
    void ClearSharableData();
    TESWaterForm *GetWaterType();
    void SetWaterType(TESWaterForm *);
    ImpactSwap *QImpactSwap();
    TESWaterForm *GetLODWaterType();
    void SetLODWaterType(TESWaterForm *);
    float GetLODWaterHeight();
    void SetLODWaterHeight(float);
    BGSMusicType *GetMusicType();
    void SetMusicType(BGSMusicType *);
    virtual bool GetMapNameForLocation(BSStringT<char> &, NiPoint3);
    virtual void GetGrassForLocation(NiPoint2, NiPoint2, TESGrassAreaParam *, uint);
    TESObjectCELL *GetCellFromWorldCoord(const NiPoint3 &);
    TESObjectCELL *GetCellFromCellCoord(int, int);
    TESObjectCELL *GetCellFromKey(uint);
    TESObjectCELL *GetCellByEditorID(const char *);
    TESObjectCELL *GetCellByIndex(uint);
    uint GetCellCount();
    bool AddCell(TESObjectCELL *);
    void ReleaseCell(TESObjectCELL *);
    void ClearCellMap();
    BSSimpleList<TESObjectREFR *> *GetOverlappedMultiBoundRefs(TESObjectCELL *);
    void AddMultiBoundRef(TESObjectREFR *);
    void ClearMultiBoundRefs();
    BSPortalGraph *GetPortalGraph();
    BSPortalGraph *CreatePortalGraph();
    void ClearPortalGraph();
    void AddToPersistentRefData(TESObjectREFR *);
    void RemoveFromPersistentRefData(TESObjectREFR *);
    void ClearPersistentRefData();
    void AddPersistentRef(TESObjectREFR *);
    void RemovePersistentRef(TESObjectREFR *);
    TESObjectCELL *GetPersistentCell();
    TESObjectCELL *CreatePersistentCell();
    void AssignPersistentRefsToCells();
    void AssignPersistentRefsToCell(TESObjectCELL *);
    void BuildTeleportDoorList(BSSimpleArray<TESObjectREFR *, 1024> &);
    void BuildTeleportDoorList(BSSimpleList<TESObjectREFR *> *);
    BSSimpleList<TESObjectREFR *> *BuildMapMarkerList(bool);
    BSSimpleList<TESObjectREFR *> *BuildAudioMarkerList(bool);
    void AddMapMarkersToList(BSSimpleList<TESObjectREFR *> *);
    void AddAudioMarkersToList(BSSimpleList<TESObjectREFR *> *);
    TESObjectREFR *FindFirstReference(TESObject *, bool);
    int RemoveDuplicateReferences();
    void EnumReferencesCloseToPoint(
        const NiPoint3 &,
        float,
        const NiPoint3 &,
        float,
        bool (*)(TESObjectREFR *, int),
        int
    );
    virtual bool IsParentForm();
    virtual bool IsFormTypeChild(unsigned char);
    bool IsPointInBorderRegion(const NiPoint3 &);

    static int GetKeyForCellCoord(short, short);
    static int GetKeyForWorldCoord(const NiPoint3 &);
    static void GetCellCoordForKey(uint, short &, short &);
    static bool IsFixedRef(TESObjectREFR *);
    static bool IsFormTypeWorldChild(unsigned char);

protected:
    OFFSET_DATA *GetOffsetData(TESFile *);
    OFFSET_DATA *CreateOffsetData(TESFile *);
    void FreeOffsetData();

    NiTPointerMap<int, TESObjectCELL *> *pCellMap; // 0x40
    TESObjectCELL *pPersistentCell; // 0x44
    TESTerrainLODManager TerrainLODManager; // 0x48
    BGSTerrainManager *pTerrainManager; // 0x4c
    TESClimate *pClimate; // 0x50
    TESImageSpace *pImageSpace; // 0x54
    ImpactSwap *pImpactSwap; // 0x58
    unsigned char cFlags; // 0x5c
    unsigned short sParentUseFlags; // 0x5e
    NiTPointerMap<uint, BSSimpleList<TESObjectREFR *> *> FixedPersistentRefMap; // 0x60
    BSSimpleList<TESObjectREFR *> MobilePersistentRefList; // 0x70
    NiTPointerMap<uint, BSSimpleList<TESObjectREFR *> *> *pOverlappedMultiboundMap; // 0x78
    NiPointer<BSPortalGraph> spPortalGraph; // 0x7c
    TESWorldSpace *pParentWorld; // 0x80
    TESWaterForm *pWorldWater; // 0x84
    TESWaterForm *pLODWater; // 0x88
    float fLODWaterHeight; // 0x8c
    WORLD_MAP_DATA WorldMapData; // 0x90
    WORLD_MAP_OFFSET_DATA WorldMapOffsetData; // 0xa0
    BGSMusicType *pMusicType; // 0xac
    NiPoint2 MinimumCoords; // 0xb0
    NiPoint2 MaximumCoords; // 0xb8
    NiTMap<TESFile *, OFFSET_DATA *> OffsetDataMap; // 0xc0
    float fDefaultLandHeight; // 0xd0
    float fDefaultWaterHeight; // 0xd4
    BGSEncounterZone *pEncounterZone; // 0xd8
    TESTexture CanopyShadowTexture; // 0xdc
    TESTexture WaterNoiseTexture; // 0xe8
    static BSCriticalSection PersistentDataCritSection;
};
