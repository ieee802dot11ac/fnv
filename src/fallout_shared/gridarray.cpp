#include "gridarray.h"
#include <cstdlib>

GridArray::GridArray() {}

GridArray::~GridArray() {}

void GridArray::Init() {
    iCenterY = -10000;
    iCenterX = -10000;
}

void GridArray::DetachAll() {
    for (int x = 0; x < iDimension; x++) {
        for (int y = 0; y < iDimension; y++) {
            Detach(x, y);
        }
    }
}

bool GridArray::SetCenter(int aiX, int aiY) {
    int dx = aiX - iCenterX;
    int dy = aiY - iCenterY;
    Shift(dx, dy);
    if (dx == 0 && dy == 0)
        return false;
    return true;
}

void GridArray::Shift(int aiCols, int aiRows) {
    iCenterX += aiCols;
    iCenterY += aiRows;
    if (abs(aiCols) < iDimension && abs(aiRows) < iDimension) {
        for (int x = aiCols; x >= 0; x--) {
        }
        for (int y = aiRows; y >= 0; y--) {
        }
        return;
    }
    this->DetachAll();
}
