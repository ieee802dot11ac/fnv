#pragma once

#include "winnt.h"
#include <types.h>
#include <types_compat.h>
#include "nisystem/nimemobject.h"

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
