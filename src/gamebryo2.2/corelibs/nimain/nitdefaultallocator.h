#pragma once

#include <types.h>
#include <cstddef>

template <typename T>
class NiTMallocInterface {
public:
    static T *Allocate(size_t);
    static void Deallocate(T *);
};

template <typename T>
class NiTNewInterface {
public:
    static T *Allocate(size_t);
    static void Deallocate(T *);
};
