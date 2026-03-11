#pragma once

#include <types.h>
#include <types_compat.h>

class MemoryManager {
public:
    ~MemoryManager();
    void AddPool(uint, uint, char *);
    void *Allocate(uint, const char *, const int, const char *);
    void *Allocate(uint);
    void *AllocatePhysical(uint, uint);
    void *TryAndAllocate(uint);
    void *Reallocate(void *, uint, const char *, const int, const char *);
    void *Reallocate(void *, uint);
    void Deallocate(void *);
    void DeallocatePhysical(void *, uint, uint);
    void *DoSystemAllocation(uint, bool);
    void DoSystemDeallocation(void *, bool);
    // MemoryContextTracker &GetContextTracker();
    // MemoryUsageTracker *GetUsageTracker();
    // ScrapHeap *GetThreadScrapHeap();
    void Memset(void *, const int, uint) const;
    void Memcpy(void *, void *, uint) const;
    void CheckMemoryIntegrity(bool);
    uint Size(const void *) const;
    uint GetNumHeaps() const;
    uint GetNumPhysicalHeaps() const;
    // bool GetHeapStats(uint, bool, HeapStats *) const;
    // bool GetPhysicalHeapStats(uint, bool, HeapStats *) const;
    // bool GetDefaultHeapStats(uint, bool, HeapStats *) const;
    int GetCalculatedMemoryUsed();
    int GetReportedMemoryUsed();
    // int OutputDebugInfo(IMemoryManagerFile *, bool);
    // IMemoryHeap *GetHeapByIndex(uint) const;
    // IMemoryHeap *GetHeapForPointer(const void *) const;
    // IMemoryHeap *GetHeapForPhysicalPointer(const void *) const;
    // IMemoryHeap *GetMemHeap(_XALLOC_ATTRIBUTES *);
    MemoryManager(const MemoryManager &);

    static MemoryManager &Instance() { return s_Instance; }
    static void CheckDelayedFreeBlocks();
    static void EnableDelayedFree();
    static void DisableDelayedFree();
    static void SetCheckMemOnFree(bool);
    static bool QDelayedFreeEnabled();
    static bool QCheckMemOnFree();
    static const int DEFAULT_ALIGNMENT;

protected:
    MemoryManager();

    void Initialize();
    void InitializeStandard();
    void RegisterMemoryManager();
    void SpecifyMemoryLayout();
    void SpecifyPools();
    void SetupDuplicatedPools();
    void ClearDuplicatedPools();
    // uint ProcessMemoryProblem(IMemoryHeap *, int, bool *);
    void InitializeStackTrace();
    // int OutputModuleInfoToFile(IMemoryManagerFile *);
    // int OutputPoolInfoToFile(IMemoryManagerFile *);
    // int OutputHeapInfoToFile(IMemoryManagerFile *, bool);
    void InitializeTrackers();
    void UpdateSystemMemoryUsage();

    static MemoryManager s_Instance;
    static const int MIN_MEM_SIZE;
    static bool bCheckFreeBlocksOnFree;
    static uint iDelayFreeBlocksEnabled;

private:
    // RemoteLog m_rlog; // 0x0
protected:
    bool bInitialized; // 0x040;
    // MemoryManager::SystemMemoryBlock *pSysmemBlockList; // 0x044;
    // MemoryAllocationLog *pAllocationLog; // 0x048;
    // MemoryUsageTracker *pUsageTracker; // 0x04c;
    // MemoryContextTracker kContextTracker; // 0x050;
    uint16_t iNumHeaps; // 0x210;
    uint16_t iNumPhysicalHeaps; // 0x212;
    // IMemoryHeap **ppHeaps; // 0x214;
    // IMemoryHeap *pHeapsByContextA[66]; // 0x218;
    // BSMap<unsigned long, ScrapHeap *> kThreadScrapHeapMap; // 0x320;
    // IMemoryHeap **ppPhysicalHeaps; // 0x330;
    bool bSpecialHeaps; // 0x334;
    bool bAllowPoolUse; // 0x335;
    uint iSysAllocBytes; // 0x338;
    uint iMallocBytes; // 0x33c;
    void *iLoadAddress; // 0x340;
    uint iImageSize; // 0x344;
    bool bCaptureStack; // 0x348;
};

#define BS_MEM_OVERLOADS                                                                 \
    void *operator new(size_t s, const char *file, int line, const char *func) {         \
        return MemoryManager::Instance().Allocate(s, file, line, func);                  \
    }                                                                                    \
    void *operator new[](size_t s, const char *file, int line, const char *func) {       \
        return MemoryManager::Instance().Allocate(s, file, line, func);                  \
    }                                                                                    \
    void operator delete(void *v) { MemoryManager::Instance().Deallocate(v); }           \
    void operator delete[](void *v) { MemoryManager::Instance().Deallocate(v); }
