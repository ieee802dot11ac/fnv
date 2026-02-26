#pragma once

class NiRTTI {
public:
    NiRTTI(const char *, const NiRTTI *);
    const char *GetName() const { return m_pcName; }
    const NiRTTI *GetBaseRTTI() const { return m_pkBaseRTTI; }

protected:
    const char *m_pcName; // 0x0
    const NiRTTI *m_pkBaseRTTI; // 0x4
};
