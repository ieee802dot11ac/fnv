#pragma once

#include "nisystem/nimemobject.h"

class NiObjectGroup : public NiMemObject {
public:
    NiObjectGroup(uint32_t);
    ~NiObjectGroup();
    void *Allocate(uint32_t);
    void DecRefCount();
    void SetSize(uint32_t);
    uint32_t GetSize() const;

private:
    uint32_t m_uiSize; // 0x0
    void *m_pvBuffer; // 0x4
    void *m_pvFree; // 0x8
    uint32_t m_uiRefCount; // 0xc
};
