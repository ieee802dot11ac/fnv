#pragma once

#include "types.h"

class BSExtraData {
public:
    BSExtraData(const BSExtraData &);
    BSExtraData(unsigned char);
    BSExtraData();
    virtual ~BSExtraData();
    void SetExtraType(unsigned char);
    unsigned char GetExtraType();
    virtual bool Compare(BSExtraData *);

protected:
    void SetNext(BSExtraData *);
    BSExtraData *GetNext();
    u8 cEtype; // 0x4
    BSExtraData *pNext; // 0x8
};
