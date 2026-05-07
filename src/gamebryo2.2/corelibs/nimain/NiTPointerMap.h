#pragma once

#include "nimain/NiTMap.h"
#include "nimain/NiTPointerAllocator.h"

template <typename Key, typename Value>
class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<unsigned int>, Key, Value> {
public:
    NiTPointerMap(const NiTPointerMap<Key, Value> &);
    NiTPointerMap(unsigned int);
    virtual ~NiTPointerMap();
    virtual NiTMapItem<Key, Value> *NewItem();
    virtual void DeleteItem(NiTMapItem<Key, Value> *);
};
