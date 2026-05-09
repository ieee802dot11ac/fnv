#pragma once

#include "nimain/NiTPointerAllocator.h"
#include "types.h"

template <typename T>
class NiTListItem {
public:
    NiTListItem<T> *m_pkNext; // 0x0
    NiTListItem<T> *m_pkPrev; // 0x4
    T m_element; // 0x8
};

template <typename Alloc, typename T>
class NiTListBase {
public:
    struct AntiBloatAllocator : public NiTPointerAllocator<uint> {
        uint m_uiCount;
    };

    uint GetSize() const;
    bool IsEmpty() const;
    void *GetHeadPos() const;
    void *GetTailPos() const;
    void *GetNextPos(void *) const;
    void *GetPrevPos(void *) const;
    void MoveToBefore(void *, void *);
    void MoveToAfter(void *, void *);

protected:
    NiTListBase<Alloc, T>();
    ~NiTListBase<Alloc, T>();
    void AddNodeHead(NiTListItem<T> *);
    void AddNodeTail(NiTListItem<T> *);
    void *AddNodeAfter(void *, NiTListItem<T> *);
    void *AddNodeBefore(void *, NiTListItem<T> *);

    NiTListItem<T> *m_pkHead; // 0x0
    NiTListItem<T> *m_pkTail; // 0x4
    AntiBloatAllocator m_kAllocator; // 0x8

private:
    NiTListBase<Alloc, T>(const NiTListBase<Alloc, T> &);
};
