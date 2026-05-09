#pragma once

#include "types.h"

class NiGeometry;

class NiVisibleArray {
public:
    NiVisibleArray(uint, uint);
    NiVisibleArray();
    ~NiVisibleArray();
    void Add(NiGeometry &);
    void RemoveAll();
    void SetAt(uint, NiGeometry &);
    NiGeometry &RemoveAtAndFill(uint);
    const NiGeometry &GetAt(uint) const;
    NiGeometry &GetAt(uint);
    uint GetCount() const;
    uint GetAllocatedSize() const;
    void SetAllocatedSize(uint);
    uint GetGrowBy() const;
    void SetGrowBy(uint);

protected:
    NiGeometry **m_ppkArray; // 0x0
    uint m_uiCurrentSize; // 0x4
    uint m_uiAllocatedSize; // 0x8
    uint m_uiGrowBy; // 0xc
};
