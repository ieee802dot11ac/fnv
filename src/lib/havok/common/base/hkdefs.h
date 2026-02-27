#pragma once
#include <types.h>
#include <types_compat.h>
// FAKE HEADER!
// i don't want to spam op news and op dels everywhere, thus this

#define HKMEMOPS                                                                         \
    static void *operator new(size_t, void *);                                           \
    static void *operator new(size_t);                                                   \
    static void operator delete(void *, void *);                                         \
    static void operator delete(void *);

#define HKMEMOPS_ARR                                                                     \
    HKMEMOPS                                                                             \
    static void *operator new[](size_t, void *);                                         \
    static void *operator new[](size_t);                                                 \
    static void operator delete[](void *, void *);                                       \
    static void operator delete[](void *);
