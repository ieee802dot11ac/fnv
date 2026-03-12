#pragma once

class TESObjectCELL;

class TESChildCell {
public:
    virtual TESObjectCELL *GetSaveParentCell();
    TESChildCell(const TESChildCell &);
    TESChildCell();
    TESChildCell &operator=(const TESChildCell &);
};
