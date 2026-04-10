#pragma once

#include <types.h>
#include <types_compat.h>

struct NiMemObject {
    static void *operator new(size_t, void *);
    static void *operator new(size_t, char const *, int, char const *);
    static void *operator new[](size_t, void *);
    static void *operator new[](size_t, char const *, int, char const *);

private:
    static void *operator new(size_t);
    static void *operator new[](size_t);

public:
    static void operator delete(void *, uint);
    static void operator delete(void *, void *);
    static void operator delete(void *, char const *, int, char const *);
    static void operator delete[](void *, uint);
    static void operator delete[](void *, char const *, int, char const *);
};
