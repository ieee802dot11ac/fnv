#pragma once

#include "gamebryo2.2/corelibs/nimain/nirtti.h"
#include "gamebryo2.2/corelibs/nimain/nitarray.h"
#include "nimain/nifixedstring.h"
#include <types.h>

char *NiGetViewerString(const char *pcRttiName);
char *NiGetViewerString(const char *pcPrefix, bool bValue);
char *NiGetViewerString(const char *pcPrefix, s8 cValue);
char *NiGetViewerString(const char *pcPrefix, u8 ucValue);
char *NiGetViewerString(const char *pcPrefix, s16 sValue);
char *NiGetViewerString(const char *pcPrefix, u16 usValue);
char *NiGetViewerString(const char *pcPrefix, int iValue);
char *NiGetViewerString(const char *pcPrefix, uint uiValue);
char *NiGetViewerString(const char *pcPrefix, float fValue);
char *NiGetViewerString(const char *pcPrefix, void *pvValue);
char *NiGetViewerString(const char *pcPrefix, const char *pcValue);

inline void NiAddViewerString(const NiRTTI *pkRTTI, NiTPrimitiveArray<char *> *pStrings) {
    char *str = NiGetViewerString(pkRTTI->GetName());
    pStrings->Add(str);
}

inline void NiAddViewerString(
    const char *pcPrefix, const NiFixedString &kValue, NiTPrimitiveArray<char *> *pStrings
) {
    char *str = NiGetViewerString(pcPrefix, kValue);
    pStrings->Add(str);
}

template <typename T>
inline void
NiAddViewerString(const char *pcPrefix, T &pValue, NiTPrimitiveArray<char *> *pStrings) {
    char *str = NiGetViewerString(pcPrefix, pValue);
    pStrings->Add(str);
}

template <typename T>
inline void
NiAddViewerString(const char *pcPrefix, T *pValue, NiTPrimitiveArray<char *> *pStrings) {
    char *str = NiGetViewerString(pcPrefix, pValue);
    pStrings->Add(str);
}
