#pragma once
#include "../win_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

#ifdef __cplusplus
}
#endif
