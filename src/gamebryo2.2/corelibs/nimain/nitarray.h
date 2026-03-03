#pragma once

#include <types.h>
#include "nitdefaultallocator.h"

template <typename T, typename Allocator = NiTMallocInterface<T> >
class NiTArray {
public:
    NiTArray(uint, uint);
    virtual ~NiTArray();
    uint GetSize() const;
    uint GetEffectiveSize() const;
    uint GetAllocatedSize() const;
    uint GetGrowBy() const;
    void SetSize(uint);
    void SetGrowBy(uint);
    T *GetBase();
    T &GetAt(uint) const;
    void SetAt(uint, T &);
    uint SetAtGrow(uint, T &);
    uint Add(const T &);
    uint AddFirstEmpty(T &);
    uint AddLastEmpty(T &);
    uint InsertAt(uint, T &);
    T *QBase();
    T RemoveAt(uint);
    T RemoveAtAndFill(uint);
    T RemoveEnd();
    void RemoveAll();
    uint Remove(T &);
    void Compact();
    void UpdateSize();

protected:
    T *m_pBase; // 0x4
    uint16_t m_usMaxSize; // 0x8
    uint16_t m_usSize; // 0xa
    uint16_t m_usESize; // 0xc
    uint16_t m_usGrowBy; // 0xe

private:
    NiTArray(const NiTArray<T> &);
    NiTArray<T> &operator=(const NiTArray<T> &);
};

template <typename T>
class NiTPrimitiveArray : public NiTArray<T> {
public:
    NiTPrimitiveArray(const NiTPrimitiveArray<T> &);
    NiTPrimitiveArray(uint, uint);
    virtual ~NiTPrimitiveArray();
    NiTPrimitiveArray<T> &operator=(const NiTPrimitiveArray<T> &);
};
