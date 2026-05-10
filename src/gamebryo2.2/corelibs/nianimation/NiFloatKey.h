#pragma once

#include "nianimation/NiAnimationKey.h"

class NiFloatKey : public NiAnimationKey {
public:
    ~NiFloatKey();
    void SetValue(float);
    float GetValue() const;
    NiFloatKey *GetKeyAt(uint, u8);

    static int RegisterLoader();
    static void
        RegisterSupportedFunctions(NiAnimationKey::KeyContent, NiAnimationKey::KeyType);
    static float
    GenInterp(float, NiFloatKey *, NiAnimationKey::KeyType, uint, uint &, u8);
    static u8 GetKeySize(NiAnimationKey::KeyType);
    static NiAnimationKey *(*GetCreateFunction(NiAnimationKey::KeyType))(NiStream &, uint);
    static void (*GetInterpFunction(NiAnimationKey::KeyType))(
        float, const NiAnimationKey *, const NiAnimationKey *, void *
    );
    static bool (*GetEqualFunction(NiAnimationKey::KeyType))(
        const NiAnimationKey &, const NiAnimationKey &
    );
    static void (*GetSaveFunction(NiAnimationKey::KeyType))(
        NiStream &, NiAnimationKey *, uint
    );
    static void (*GetCopyFunction(NiAnimationKey::KeyType))(
        NiAnimationKey *, const NiAnimationKey *
    );
    static NiAnimationKey *(*GetArrayFunction(NiAnimationKey::KeyType))(uint);
    static void (*GetDeleteFunction(NiAnimationKey::KeyType))(NiAnimationKey *);
    static bool (*GetInsertFunction(NiAnimationKey::KeyType))(
        float, NiAnimationKey *&, uint &
    );
    static void (*GetFillDerivedFunction(NiAnimationKey::KeyType))(
        NiAnimationKey *, uint, u8
    );
    static void SetDefault(float);

protected:
    void LoadBinary(NiStream &);
    NiFloatKey(float, float);

    float m_fValue; // 0x4
    static float ms_fDefault;

    static NiAnimationKey *CreateFromStream(NiStream &, uint);
    static void SaveToStream(NiStream &, NiAnimationKey *, uint);
    static void SaveBinary(NiStream &, NiAnimationKey *);
    static void Copy(NiAnimationKey *, const NiAnimationKey *);
    static NiAnimationKey *CreateArray(uint);
    static void DeleteArray(NiAnimationKey *);
    static bool Insert(float, NiAnimationKey *&, uint &);
    static float ComputeMaxCurvature(NiAnimationKey *, uint);
    static void
    Interpolate(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static void
    InterpolateD1(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static void
    InterpolateD2(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static bool Equal(const NiAnimationKey &, const NiAnimationKey &);
    static void FillDerivedVals(NiAnimationKey *, uint, u8);
    static float GenInterpDefault(float, NiFloatKey *, NiAnimationKey::KeyType, uint, u8);
};
