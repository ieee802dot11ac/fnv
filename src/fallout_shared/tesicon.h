#pragma once

#include "fallout_shared/testexture.h"

class TESIcon : public TESTexture {
public:
    virtual char *GetDefaultPath() const;
    TESIcon(const TESIcon &);
    TESIcon();
    TESIcon &operator=(const TESIcon &);
};
