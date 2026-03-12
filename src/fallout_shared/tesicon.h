#pragma once

#include "fallout_shared/testexture.h"

class TESIcon : public TESTexture {
    virtual char *GetDefaultPath() const;
    TESIcon(const TESIcon &);
    TESIcon();
    ~TESIcon();
    TESIcon &operator=(const TESIcon &);
};
