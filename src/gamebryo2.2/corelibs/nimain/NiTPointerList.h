#pragma once

#include "nimain/NiTPointerAllocator.h"
#include "nimain/NiTPointerListBase.h"

template <typename T>
class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<uint>, T> {
    NiTPointerList();
    ~NiTPointerList();
};
