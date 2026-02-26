#pragma once

#include "winnt.h"
#include <types.h>

struct NiMemObject {
    static void *operator new(uint, void *);
    static void *operator new(uint, char const *, int, char const *);

private:
    static void *operator new(uint);

public:
    static void *operator new[](uint, void *);
    static void *operator new[](uint, char const *, int, char const *);

private:
    static void *operator new[](uint);

public:
    static void operator delete(void *, uint);
    static void operator delete(void *, void *);
    static void operator delete(void *, char const *, int, char const *);
    static void operator delete[](void *, uint);
    static void operator delete[](void *, char const *, int, char const *);
};

class NiRefObject : public NiMemObject {
public:
    // it's either this, or some other thread-type primitive
    // in any case: fuck you todd.
    NiRefObject() { InterlockedIncrement((LONG *)&ms_uiObjects); }
    virtual ~NiRefObject() { InterlockedDecrement((LONG *)&ms_uiObjects); }
    void IncRefCount();
    void DecRefCount();
    void BETAVERSION_TEST_ClearRefCount();
    uint GetRefCount() const;
    static uint GetTotalObjectCount();

protected:
    virtual void DeleteThis();
    uint m_uiRefCount; // 0x4
private:
    static uint ms_uiObjects;
};
