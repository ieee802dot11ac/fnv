#pragma once

#include "nimain/NiTSet.h"
#include "nimain/nitdefaultallocator.h"

template <typename T>
class NiTPrimitiveSet : public NiTSet<T, NiTMallocInterface<T> > {
public:
    NiTPrimitiveSet(const NiTPrimitiveSet &);
    NiTPrimitiveSet(uint);
    ~NiTPrimitiveSet();
};
