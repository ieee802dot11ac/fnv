#pragma once

#include "winnt.h"

struct PMD { /* Size=0xc */
    int mdisp; // 0x0
    int pdisp; // 0x4
    int vdisp; // 0x8
};

struct TypeDescriptor { /* Size=0x8 */
    const void *pVFTable; // 0x0
    void *spare; // 0x4
    char name[]; // 0x8
};

struct _s_CatchableType { /* Size=0x1c */
    unsigned int properties; // 0x00
    TypeDescriptor *pType; // 0x04
    PMD thisDisplacement; // 0x08
    int sizeOrOffset; // 0x14
    void (*copyFunction)(); // 0x18
};

struct _s_CatchableTypeArray { /* Size=0x4 */
    int nCatchableTypes; // 0x0
    const _s_CatchableType *arrayOfCatchableTypes[]; // 0x4
};

struct _s_ThrowInfo { /* Size=0x10 */
    unsigned int attributes; // 0x0
    void (*pmfnUnwind)(); // 0x4
    int (*pForwardCompat)(...); // 0x8
    const _s_CatchableTypeArray *pCatchableTypeArray; // 0xc
};

struct EHExceptionRecord { /* Size=0x20 */
    struct EHParameters { /* Size=0xc */
        unsigned int magicNumber; // 0x0
        void *pExceptionObject; // 0x4
        const _s_ThrowInfo *pThrowInfo; // 0x8
    };
    unsigned int ExceptionCode; // 0x00
    unsigned int ExceptionFlags; // 0x04
    EXCEPTION_RECORD *ExceptionRecord; // 0x08
    void *ExceptionAddress; // 0x0c
    unsigned int NumberParameters; // 0x10
    EHExceptionRecord::EHParameters params; // 0x14
};

void _CxxThrowException(void *pExceptionObject, const _s_ThrowInfo *pThrowInfo);
