#pragma once
#include "gamebryo2.2/corelibs/nimain/nifixedstring.h"
#include "gamebryo2.2/corelibs/nimain/niobjectgroup.h"
#include "gamebryo2.2/corelibs/nimain/nitarray.h"
#include <types.h>
#include "niobject.h"
#include "nibinarystream.h"

#define VERSION(hh, hl, lh, ll) ((u8(hh) << 24) | (u8(hl) << 16) | (u8(lh) << 8) | u8(ll))

class NiStream {
public:
    NiStream();
    virtual ~NiStream();
    void InsertObject(NiObject *);
    void RemoveObject(NiObject *);
    void RemoveAllObjects();
    uint GetObjectCount() const;
    NiObject *GetObjectAt(uint) const;
    virtual bool Load(NiBinaryStream *);
    virtual bool Load(char *, int);
    virtual bool Load(char const *);
    virtual bool Save(NiBinaryStream *);
    virtual bool Save(char *&, int &);
    virtual bool Save(char const *);
    bool GetSaveAsLittleEndian();
    void SetSaveAsLittleEndian(bool);
    bool GetSourceIsLittleEndian();
    bool QEndian();
    bool QEndianSave();
    enum ThreadStatus {
        IDLE = 0,
        LOADING,
        CANCELLING,
        PAUSING,
        PAUSED,
    };
    class LoadState;
    void BackgroundLoad();

protected:
    void BackgroundLoadBegin();

public:
    void BackgroundLoadBegin(NiBinaryStream *);
    void BackgroundLoadBegin(char const *);
    NiStream::ThreadStatus BackgroundLoadPoll(NiStream::LoadState *);
    void BackgroundLoadPause();
    void BackgroundLoadResume();
    void BackgroundLoadCancel();
    bool BackgroundLoadFinish();
    void BackgroundLoadCleanup();
    bool BackgroundLoadGetExitStatus() const;
    virtual void BackgroundLoadOnExit();
    // NiProcessorAffinity const &GetAffinity() const;
    // void SetAffinity(NiProcessorAffinity const &);
    // NiThread::Priority const GetPriority() const;
    // void SetPriority(NiThread::Priority const);
    class BackgroundLoadProcedure;
    static uint GetVersionFromString(char const *pcVersionString);
    static uint GetVersion(uint hihi, uint hilo, uint lohi, uint lolo) {
        return VERSION(hihi, hilo, lohi, lolo);
    }
    uint GetFileVersion() const { return m_uiNifFileVersion; }
    uint GetFileUserDefinedVersion() const { return m_uiNifFileUserDefinedVersion; }
    void SetLastError(uint);
    uint GetLastError() const;
    char const *GetLastErrorMessage() const;
    void ResetLastErrorInfo();
    void LoadCString(char *&);
    void SaveCString(char const *);
    void LoadFixedString(NiFixedString &);
    void SaveFixedString(NiFixedString const &);
    void LoadCStringAsFixedString(NiFixedString &);
    virtual bool RegisterFixedString(NiFixedString const &);
    virtual bool RegisterSaveObject(NiObject *);
    virtual void ChangeObject(NiObject *);
    virtual uint GetLinkIDFromObject(NiObject const *) const;
    virtual void SaveLinkID(NiObject const *);
    void ReadLinkID();
    uint ReadMultipleLinkIDs();
    NiObject *ResolveLinkID();
    NiObject *GetObjectFromLinkID();
    uint GetNumberOfLinkIDs();
    void SetNumberOfLinkIDs(uint);
    NiObjectGroup *GetGroupFromID(uint) const;
    uint GetIDFromGroup(NiObjectGroup *) const;
    NiBinaryStream &Istr();
    NiBinaryStream &Ostr();
    // void SetTexture(NiTexture *);
    // void GetTexture(char const *, NiPointer<NiTexture> &) const;
    // NiSearchPath *GetSearchPath() const;
    // void SetSearchPath(NiSearchPath *);
    char const *GetLastLoadedRTTI() const;
    unsigned short GetLastNiAVObjectFlags() const;
    void SetLastNiAVObjectFlags(unsigned short);
    unsigned short GetLastNiTimeControllerFlags() const;
    void SetLastNiTimeControllerFlags(unsigned short);
    unsigned short GetLastNiPropertyFlags() const;
    void SetLastNiPropertyFlags(unsigned short);
    static void LockCleanupSection();
    static void UnlockCleanupSection();
    typedef NiObject *(*CreateFunction)();
    static int RegisterLoader(char const *, NiObject *(*)());
    static void UnregisterLoader(char const *);
    typedef void (*PostProcessFunction)(NiStream &, NiObject *);
    static void RegisterPostProcessFunction(void (*)(NiStream &, NiObject *));
    static void UnregisterPostProcessFunction(void (*)(NiStream &, NiObject *));
    static void _SDMInit();
    static void _SDMShutdown();
    static NiObject *CreateObjectByRTTI(char const *);
    static uint const NULL_LINKID;
    // BSStreamHeader m_BSStreamHeader; // 0x4
protected:
    NiTPrimitiveArray<NiObjectGroup *> m_kGroups; // 0xC8
    uint m_uiNifFileVersion; // 0xD8
    uint m_uiNifFileUserDefinedVersion; // 0xDC
    char m_acFileName[260]; // 0xE0
    bool m_bSaveLittleEndian; // 0x1E4
    bool m_bSourceIsLittleEndian; // 0x1E5
    // NiSearchPath *m_pkSearchPath; // 0x1E8
    // NiTLargeObjectArray<NiPointer<NiObject> > m_kObjects; // 0x1EC
    // NiTLargePrimitiveArray<unsigned int> m_kObjectSizes; // 0x204
    // NiTLargeObjectArray<NiPointer<NiObject> > m_kTopObjects; // 0x21C
    // NiTLargeObjectArray<NiFixedString> m_kFixedStrings; // 0x234
    NiBinaryStream *m_pkIstr; // 0x24C
    NiBinaryStream *m_pkOstr; // 0x250
    // NiTPrimitiveSet<unsigned int> m_kLinkIDs; // 0x254
    uint m_uiLinkIndex; // 0x260
    // NiTPrimitiveSet<unsigned int> m_kLinkIDBlocks; // 0x264
    uint m_uiLinkBlockIndex; // 0x270
    // NiTPointerMap<NiObject const *,unsigned int> m_kRegisterMap; // 0x274
    unsigned short m_usNiAVObjectFlags; // 0x284
    unsigned short m_usNiTimeControllerFlags; // 0x286
    unsigned short m_usNiPropertyFlags; // 0x288
    NiStream::ThreadStatus m_eBackgroundLoadStatus; // 0x28C
    bool m_bBackgroundLoadExitStatus; // 0x290
    uint m_uiLoad; // 0x294
    uint m_uiLink; // 0x298
    uint m_uiPostLink; // 0x29C
    // NiThread *m_pkThread; // 0x2A0
    NiStream::BackgroundLoadProcedure *m_pkBGLoadProc; // 0x2A4
    // NiThread::Priority m_ePriority; // 0x2A8
    // NiProcessorAffinity m_kAffinity; // 0x2AC
    char m_acLastLoadedRTTI[260]; // 0x2B4
    uint m_uiLastError; // 0x3B8
    char m_acLastErrorMessage[260]; // 0x3BC
    char m_acFilePath[260]; // 0x4C0
public:
    char const *GetFileName();
    void SetFilePath(char const *);
    static void ResetSearchPath();
    bool GetNextSearchPath(char *, uint);

protected:
    virtual bool LoadHeader();
    virtual void SaveHeader();
    virtual bool LoadStream();
    virtual bool SaveStream();
    virtual void RegisterObjects();
    virtual void LoadTopLevelObjects();
    virtual void SaveTopLevelObjects();
    virtual bool LoadObject();
    virtual uint PreSaveObjectSizeTable();
    virtual bool SaveObjectSizeTable(uint);
    virtual bool LoadObjectSizeTable();
    void FreeLoadData();
    void DoThreadPause();
    void SetSelectiveUpdateFlagsForOldVersions();
    // void SetSelectiveUpdateFlagsTTTFRecursive(NiAVObject *);
    void LoadRTTIString(char *);
    bool LoadRTTI();
    void SaveRTTI();
    void RTTIError(char const *);
    uint GetStringID(NiFixedString const &);
    void SaveFixedStringTable();
    bool LoadFixedStringTable();
    void LoadObjectGroups();
    void SaveObjectGroups();
    void UpdateObjectGroups();
    // typedef NiTPrimitiveArray<NiObjectGroup *> NiObjectGroupArray;
    void BackgroundLoadEstimateProgress(NiStream::LoadState &);
    // static NiSemaphore m_kSemaphore;
    enum {
        STREAM_OKAY = 0,
        FILE_NOT_LOADED,
        NOT_NIF_FILE,
        OLDER_VERSION,
        LATER_VERSION,
        NO_CREATE_FUNCTION,
        ENDIAN_MISMATCH,
    };
    enum {
        SKIPPABLE_MASK = 32768, // 0x8000
    };
    static uint const ms_uiNifMinVersion;
    static uint const ms_uiNifMaxVersion;
    static uint const ms_uiNifMinUserDefinedVersion;
    static uint const ms_uiNifMaxUserDefinedVersion;
    // static NiTStringPointerMap<CreateFunction> *ms_pkLoaders;
    // typedef NiTPrimitiveArray<void (*)(NiStream &, NiObject *)>
    // PostProcessFunctionArray;
    // static PostProcessFunctionArray * ms_pkPostProcessFunctions;
    // static NiCriticalSection ms_kCleanupCriticalSection;
    static bool bUseDefaultPath;
};

template <typename T>
void NiStreamLoadBinary(NiStream &, T &);

template <typename T>
void NiStreamSaveBinary(NiStream &, T &);
