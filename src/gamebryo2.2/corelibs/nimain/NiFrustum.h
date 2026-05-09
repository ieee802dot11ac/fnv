#pragma once

class NiFrustum {
public:
    float m_fLeft; // 0x00
    float m_fRight; // 0x04
    float m_fTop; // 0x08
    float m_fBottom; // 0x0c
    float m_fNear; // 0x10
    float m_fFar; // 0x14
    bool m_bOrtho; // 0x18

    NiFrustum(float, float, float, float, float, float, bool);
    NiFrustum(bool);
    char *GetViewerString(const char *) const;
};
