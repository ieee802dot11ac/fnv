#pragma once

#include "nianimation/NiFloatKey.h"

class NiLinFloatKey : public NiFloatKey {
public:
    NiLinFloatKey(float, float);

    static int RegisterLoader();
    static void
        RegisterSupportedFunctions(NiAnimationKey::KeyContent, NiAnimationKey::KeyType);

protected:
    void LoadBinary(NiStream &);

    static NiAnimationKey *CreateFromStream(NiStream &, unsigned int);
    static void SaveToStream(NiStream &, NiAnimationKey *, unsigned int);
    static void SaveBinary(NiStream &, NiAnimationKey *);
    static void Copy(NiAnimationKey *, const NiAnimationKey *);
    static NiAnimationKey *CreateArray(unsigned int);
    static void DeleteArray(NiAnimationKey *);
    static bool Insert(float, NiAnimationKey *&, unsigned int &);
    static float ComputeMaxCurvature(NiAnimationKey *, unsigned int);
    static void
    Interpolate(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static void
    InterpolateD1(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static void
    InterpolateD2(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static bool Equal(const NiAnimationKey &, const NiAnimationKey &);
    static void FillDerivedVals(NiAnimationKey *, unsigned int, unsigned char);
};
