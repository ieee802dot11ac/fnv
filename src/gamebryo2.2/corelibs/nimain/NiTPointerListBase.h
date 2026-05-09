#pragma once

#include "nimain/NiTListBase.h"
template <typename Alloc, typename T>
class NiTPointerListBase : public NiTListBase<Alloc, T> {
public:
    ~NiTPointerListBase();
    void AddHead(T &);
    void AddTail(T &);
    void *InsertBefore(void *, T &);
    void *InsertAfter(void *, T &);
    T &GetHead() const;
    T &GetTail() const;
    T &Get(void *) const;
    T &GetNext(void *&) const;
    T &GetPrev(void *&) const;
    T RemoveHead();
    T RemoveTail();
    T Remove(T &);
    T RemovePos(void *&);
    void *FindPos(T &, void *) const;
    void RemoveAll();
    void Sort(int (*)(void *, void *));

protected:
    NiTListItem<T> *NewItem();
    void DeleteItem(NiTListItem<T> *);
};
