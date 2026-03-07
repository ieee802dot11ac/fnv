#pragma once

#include "win_types.h"
#include "bscore/bsstring.h"
#include "xapilibi/minwinbase.h"

class TESForm;

class TESFile {
public:
    TESFile(const TESFile &);
    //   TESFile(const char*, const char*, NiFile::OpenMode);
    ~TESFile();
    //   bool CreateTES(const char*, const char*, NiFile::OpenMode);
    //   bool CreateTES(NiFile::OpenMode);
    //   bool OpenTES(const char*, const char*, NiFile::OpenMode, bool);
    //   bool OpenTES(NiFile::OpenMode, bool);
    bool CloseTES();
    bool DeleteTES();
    bool IsOpen();
    bool QDLC();
    void SetDLC(bool);
    //   TES_RETURN_CODE LoadTESInfo();
    //   TES_RETURN_CODE SaveTESInfo();
    //   TES_RETURN_CODE RewriteFormHeader();
    TESForm *BuildTESInfoForm();
    int GetFormCount();
    void ModFormCount(int);
    void SetFormCount(int);
    //   LANGUAGE GetFileLanguage();
    //   void SetFileLanguage(LANGUAGE);
    float GetFileVersion();
    void SetFileVersion(float);
    bool IsFileVersionTooHigh();
    uint GetFORMSize();
    char *GetPath();
    char *GetFilename();
    uint GetFileSize();
    PWIN32_FIND_DATAA GetFileData();
    void GetCreateTime(PSYSTEMTIME);
    void GetLastWriteTime(PFILETIME);
    void GetLastWriteTime(PSYSTEMTIME);
    BSStringT<char> *GetCreator();
    BSStringT<char> *GetSummary();
    //   bool MastersChecked(BSSimpleList<TESFile *>*);
    //   bool GenIndexTable(BSSimpleList<TESFile *>*, bool);
    TESFile *GetIndexFile(uint);
    char *GetIndexName(uint);
    uint GetIndexCount();
    uint GetFileIndex(TESFile *);
    void ClearMasters();
    void AddMaster(char *);
    //   bool AddMasters(BSSimpleList<TESFile *>*);
    void RemoveMaster(uint);
    bool DependsOnMaster(char *);
    bool MastersChanged();
    bool CheckLODPlugins();
    //   BSSimpleList<char *>* GetMasterList();
    unsigned char GetCompileIndex();
    void SetCompileIndex(unsigned char);
    void AddToDataHandler();
    bool CurrentGroupMayContainForm(TESForm *);
    //   void StartGroup(FORM*);
    void EndGroup();
    //   void OpenGroup(FORM*);
    void CloseGroup();
    bool FindForm(TESForm *);
    bool NextGroup();
    void StartAndEndGroupsForForm(TESForm *);
    void CloseAllOpenGroups();
    //   FORM_GROUP* GetCurrentGroup();
    //   BSSimpleList<FORM_GROUP *>* GetGroupList();
    void TESRewind(bool);
    void TESRewindChunk();
    bool NextForm(bool);
    bool GetNextForm();
    void GetTESFormNoRet();
    //   ENUM_FORM_ID GetTESForm();
    uint GetOffset();
    uint GetOffsetChunk();
    bool SetOffset(uint);
    bool SetOffsetChunk(uint);
    //   ENUM_FORM_ID GetFormAtOffset(uint);
    uint CopyCurrentFormToBuffer(void *, uint);
    //   CHUNK_ID GetTESChunk();
    bool NextChunk();
    uint GetChunkSize();
    bool GetChunkData(unsigned short &);
    bool GetChunkData(short &);
    bool GetChunkData(float &);
    bool GetChunkData(uint &);
    bool GetChunkData(int &);
    bool GetChunkData(void *, uint);
    void ClearCurrentChunk();
    bool SetFilename(char *);
    //   TES_RETURN_CODE AddTESForm(TESForm*);
    //   TES_RETURN_CODE StartForm(TESForm*);
    void LoadForm(TESForm *);
    //   TES_RETURN_CODE AddChunk(CHUNK_ID, void*, uint);
    uint CloseForm();
    //   bool ForceSaveFormHeader(FORM*, uint);
    void SetMaster(bool);
    bool GetMaster();
    void SetOptimizedFile(bool);
    bool GetOptimizedFile();
    void SetChecked(bool);
    bool GetChecked();
    void SetAltered(bool);
    bool GetAltered();
    void SetActive(bool);
    bool GetActive();
    void SetLittleEndian(bool);
    bool GetLittleEndian();
    bool QEndian();
    void SetUnicode(bool);
    bool GetUnicode();
    bool GetHasGroups();
    void SetHasGroups(bool);
    float GetPercentage();
    void CopyToBackup();
    TESFile *GetThreadSafeFile();
    TESFile *GetThreadSafeParent();
    void CopyThreadSafeParentAuxBuffer();
    void ClearAuxBuffer();
    //   void SetFile(BSFile*);
    //   BSFile* GetFile();
    //   TES_RETURN_CODE GetLastFileError();
    //   FORM* GetFormData();
    uint GetID();
    unsigned short GetFormVersion();
    bool TakeOwnership();
    void SetCached(bool);
    void SetCaching(bool);
    void ResetWithCachedFile();
    bool GetCached();
    bool GetCaching();
    uint GetMasterCount();
    void ChangeBufferSize(int);
    bool AddAuxBuffer(uint, uint);
    void SetTempIDOwner(bool);
    bool GetTempIDOwner();

    // static void DeleteFileList(BSSimpleList<TESFile *>*);
    static bool TakeFileOwnership(char *);
    static unsigned short GetFileFormVersion();
    static void SetTempIDOwnedByFile(uint, TESFile *);
    static bool GetTempIDCanLoadFromFile(uint, TESFile *);
    static TESFile *GetFileForTempID(uint);

protected:
    void RemoveFromOwnedIDMap();
    bool IsCurrentFormCompressed();
    uint GetDecompressedBufferSize();
    char *GetDecompressedBuffer();
    void FreeDecompressedBuffer();
    void DecompressCurrentForm();
    bool ReadFormHeader();
    bool ReadChunkHeader();
    //   BSSimpleList<ULARGE_INTEGER *>* GetMasterDataList();
    void ClearMasterLists();
    void ClearThreadSafeFiles();
    void SetThreadSafeParent(TESFile *);
    TESFile *GetThreadSafeFileForThread(uint);

    // TES_RETURN_CODE m_lastError; // 0x000
    TESFile *pThreadSafeParent; // 0x004
    // NiTPointerMap<uint,TESFile *>* pThreadSafeFileMap; // 0x008

    //   static NiTMap<uint,TESFile *>* pOwnedTempIDMap;
    static uint iOwnerFileCount;

private:
    uint GetFlags();
    uint GetVersionInfo();
    void InitEndian();
    //   TES_RETURN_CODE EasyWrite(void*, uint);

    //  BSFile* m_pLockedFile; // 0x00c
    // BSFile* m_pFile; // 0x010
    // TESBitArrayFile* pFormUserDataBitArray; // 0x014
    // TESBitArrayFile* pFormVersionBitArray; // 0x018
    // TESBitArrayFile* pFormIDBitArray; // 0x01c
    char m_Filename[260]; // 0x020
    char m_Path[260]; // 0x124
    char *m_pBuffer; // 0x228
    uint m_uiBufferAllocSize; // 0x22c
    uint m_firstCellOffset; // 0x230
    uint m_currCellOffset; // 0x234
    // TESObjectCELL* m_pCurrCell; // 0x238
    uint m_currRefOffset; // 0x23c
    // FORM m_currentform; // 0x240
    // CHUNK_ID m_currentchunkID; // 0x258
    uint m_actualChunkSize; // 0x25c
    uint m_filesize; // 0x260
    uint m_fileoffset; // 0x264
    uint m_formoffset; // 0x268
    uint m_chunkoffset; // 0x26c
    // FORM m_saveform; // 0x270
    uint m_saveformoffset; // 0x288
    uint m_savechunkoffset; // 0x28c
    // BSSimpleList<FORM_GROUP *> m_grouplist; // 0x290
    bool bHasGroups; // 0x298
    bool bMustEndianConvert; // 0x299
    bool bCloseFileOverride; // 0x29a
    WIN32_FIND_DATAA m_FileInfo; // 0x29c
    // FILE_HEADER fileHeaderInfo; // 0x3dc
    uint m_Flags; // 0x3e8
    // BSSimpleList<char *> listMasters; // 0x3ec
    // BSSimpleList<PULARGE_INTEGER> listMastersData; // 0x3f4
    uint iMasterCount; // 0x3fc
    TESFile **m_pMasterPtrs; // 0x400
    FILETIME DeletedFormTime; // 0x404
    unsigned char cCompileIndex; // 0x40c
    BSStringT<char> cCreatedBy; // 0x410
    BSStringT<char> cSummary; // 0x418
    char *pDecompressedFormBuffer; // 0x420
    uint iDecompressedFormBufferSize; // 0x424
    bool bCached; // 0x428
    bool bCaching; // 0x429
    bool bDLC; // 0x42a
};
