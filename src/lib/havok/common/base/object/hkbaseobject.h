#pragma once
#include "reflection/hkclass.h"

class hkBaseObject {
public:
    static hkInternalClassMember const Members[0];
    static hkClass const &staticClass();
    struct DefaultStruct;
    // hkBaseObject(hkFinishLoadedObjectFlag);
    hkBaseObject();
    virtual ~hkBaseObject();
};
