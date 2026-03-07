#pragma once

#include "bscore/memorymanager.h"
#include <types.h>

class GridArray {
public:
    GridArray(const GridArray &);
    GridArray();
    virtual ~GridArray();
    int CenterX();
    int CenterY();
    uint GetDimension();
    void SetDimension(uint);
    virtual void Init();
    virtual void DetachAll();
    virtual void KillAll();
    virtual bool SetCenter(int, int);
    virtual void Shift(int, int);
    virtual void Detach(uint, uint);
    virtual void ClearItem(uint, uint);
    virtual void MoveItem(uint, uint, uint, uint);
    virtual void SwapItem(uint, uint, uint, uint);

    BS_MEM_OVERLOADS

protected:
    int iCenterX; // 0x4
    int iCenterY; // 0x8
    uint iDimension; // 0xc
};
