#pragma once

#include "types.h"

template <typename T, typename Alloc>
class NiTSet {
public:
    NiTSet(uint);
    ~NiTSet();
    uint GetSize() const;
    T *GetBase() const;
    T &GetAt(uint);
    T &GetAt(uint) const;
    void Add(T &);
    void AddUnique(T &);
    void RemoveAt(uint);
    void OrderedRemoveAt(uint);
    bool Remove(T &);
    bool OrderedRemove(T &);
    void ReplaceAt(uint, T &);
    void RemoveAll();
    void Realloc();
    int Find(T &) const;

protected:
    void Realloc(uint);

    T *m_pBase; // 0x0
    uint m_uiAlloced; // 0x4
    uint m_uiUsed; // 0x8

private:
    NiTSet(const NiTSet<T, Alloc> &);
};
