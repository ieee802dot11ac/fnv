#include "nimain/NiViewerStrings.h"
#include "nisystem/NiMemoryDefines.h"
#include "nisystem/NiSystem.h"
#include <cstring>

char *NiGetViewerString(const char *pcRttiName) {
    uint len = strlen(pcRttiName) + 9;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        24
    );
    NiSprintf(buf, len, "--- %s ---", pcRttiName);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, bool bValue) {
    uint len = strlen(pcPrefix) + 9;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        32
    );
    if (bValue) {
        NiSprintf(buf, len, "%s = true", pcPrefix);
    } else {
        NiSprintf(buf, len, "%s = false", pcPrefix);
    }
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, char cValue) {
    uint len = strlen(pcPrefix) + 5;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        43
    );
    NiSprintf(buf, len, "%s = %c", pcPrefix, cValue);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, unsigned char ucValue) {
    uint len = strlen(pcPrefix) + 7;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        51
    );
    NiSprintf(buf, len, "%s = %u", pcPrefix, ucValue);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, short sValue) {
    uint len = strlen(pcPrefix) + 10;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        59
    );
    NiSprintf(buf, len, "%s = %hd", pcPrefix, sValue);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, unsigned short usValue) {
    uint len = strlen(pcPrefix) + 9;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        67 // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    );
    NiSprintf(buf, len, "%s = %hu", pcPrefix, usValue);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, int iValue) {
    uint len = strlen(pcPrefix) + 15;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        75
    );
    NiSprintf(buf, len, "%s = %d", pcPrefix, iValue);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, uint uiValue) {
    uint len = strlen(pcPrefix) + 14;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        83
    );
    NiSprintf(buf, len, "%s = %u", pcPrefix, uiValue);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, float fValue) {
    uint len = strlen(pcPrefix) + 20;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        107
    );
    NiSprintf(buf, len, "%s = %g", pcPrefix, fValue);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, void *pvValue) {
    uint len = strlen(pcPrefix) + 16;
    char *buf = (char *)NiMalloc(
        len,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
        123
    );
    NiSprintf(buf, len, "%s = %p", pcPrefix, pvValue);
    return buf;
}

char *NiGetViewerString(const char *pcPrefix, char const *pcValue) {
    char *buf;
    if (pcValue != nullptr) {
        uint len = strlen(pcPrefix) + strlen(pcValue) + 4;
        buf = (char *)NiMalloc(
            len,
            "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
            135
        );
        NiSprintf(buf, len, "%s = %s", pcPrefix, pcValue);
    } else {
        uint len = strlen(pcPrefix) + 8;
        buf = (char *)NiMalloc(
            len,
            "D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2.2\\CoreLibs\\NiMain\\NiViewerStrings.cpp",
            141
        );
        NiSprintf(buf, len, "%s = NULL", pcPrefix);
    }
    return buf;
}
