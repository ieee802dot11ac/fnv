#pragma once

#include <types.h>
#include <types_compat.h>

class MemoryManager {
public:
    ~MemoryManager();
    void AddPool(uint32_t, uint32_t, char *);
    void *Allocate(uint32_t, const char *, const int32_t, const char *);
    void *Allocate(uint32_t);
    void *AllocatePhysical(uint32_t, uint32_t);
    void *TryAndAllocate(uint32_t);
    void *Reallocate(void *, uint32_t, const char *, const int32_t, const char *);
    void *Reallocate(void *, uint32_t);
    void Deallocate(void *);
    void DeallocatePhysical(void *, uint32_t, uint32_t);
    void *DoSystemAllocation(uint32_t, bool);
    void DoSystemDeallocation(void *, bool);
    // MemoryContextTracker &GetContextTracker();
    // MemoryUsageTracker *GetUsageTracker();
    // ScrapHeap *GetThreadScrapHeap();
    void Memset(void *, const int32_t, uint32_t) const;
    void Memcpy(void *, void *, uint32_t) const;
    void CheckMemoryIntegrity(bool);
    uint32_t Size(const void *) const;
    uint32_t GetNumHeaps() const;
    uint32_t GetNumPhysicalHeaps() const;
    // bool GetHeapStats(uint32_t, bool, HeapStats *) const;
    // bool GetPhysicalHeapStats(uint32_t, bool, HeapStats *) const;
    // bool GetDefaultHeapStats(uint32_t, bool, HeapStats *) const;
    int32_t GetCalculatedMemoryUsed();
    int32_t GetReportedMemoryUsed();
    // int32_t OutputDebugInfo(IMemoryManagerFile *, bool);
    // IMemoryHeap *GetHeapByIndex(uint32_t) const;
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
    static const int32_t DEFAULT_ALIGNMENT;

protected:
    MemoryManager();

    void Initialize();
    void InitializeStandard();
    void RegisterMemoryManager();
    void SpecifyMemoryLayout();
    void SpecifyPools();
    void SetupDuplicatedPools();
    void ClearDuplicatedPools();
    // uint32_t ProcessMemoryProblem(IMemoryHeap *, int32_t, bool *);
    void InitializeStackTrace();
    // int32_t OutputModuleInfoToFile(IMemoryManagerFile *);
    // int32_t OutputPoolInfoToFile(IMemoryManagerFile *);
    // int32_t OutputHeapInfoToFile(IMemoryManagerFile *, bool);
    void InitializeTrackers();
    void UpdateSystemMemoryUsage();

    static MemoryManager s_Instance;
    static const int32_t MIN_MEM_SIZE;
    static bool bCheckFreeBlocksOnFree;
    static uint32_t iDelayFreeBlocksEnabled;

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
    uint32_t iSysAllocBytes; // 0x338;
    uint32_t iMallocBytes; // 0x33c;
    void *iLoadAddress; // 0x340;
    uint32_t iImageSize; // 0x344;
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
