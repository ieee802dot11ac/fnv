#pragma once

#include <win_types.h>

#pragma region Xbox RealTimeLib Exclusives

void RtlInitializeCriticalSection(struct _RTL_CRITICAL_SECTION *);
void RtlEnterCriticalSection(struct _RTL_CRITICAL_SECTION *);

#pragma region Publics

typedef struct _RTL_CRITICAL_SECTION { /* Size=0x1c */
    struct {
        unsigned int RawEvent[4];
    } Synchronization; // 0x00
    int LockCount; // 0x10
    int RecursionCount; // 0x14
    void *OwningThread; // 0x18
} CRITICAL_SECTION, *LPCRITICAL_SECTION;

inline VOID InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
    RtlInitializeCriticalSection(lpCriticalSection);
}

inline VOID EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
    RtlEnterCriticalSection(lpCriticalSection);
}
