#pragma once

#include "nianimation/NiAnimationKey.h"
#include "nimain/NiColor.h"

class NiColorKey : public NiAnimationKey {
public:
    ~NiColorKey();
    void SetColor(const NiColorA &);
    const NiColorA &GetColor() const;
    NiColorKey *GetKeyAt(unsigned int, unsigned char);

    static int RegisterLoader();
    static void
        RegisterSupportedFunctions(NiAnimationKey::KeyContent, NiAnimationKey::KeyType);
    static NiColorA GenInterp(
        float,
        NiColorKey *,
        NiAnimationKey::KeyType,
        unsigned int,
        unsigned int &,
        unsigned char
    );
    static unsigned char GetKeySize(NiAnimationKey::KeyType);
    static InterpFunction GetInterpFunction(NiAnimationKey::KeyType);
    static NiAnimationKey *(*GetCreateFunction(NiAnimationKey::KeyType))(
        NiStream &, unsigned int
    );
    static void (*GetSaveFunction(NiAnimationKey::KeyType))(
        NiStream &, NiAnimationKey *, unsigned int
    );
    static bool (*GetEqualFunction(NiAnimationKey::KeyType))(
        const NiAnimationKey &, const NiAnimationKey &
    );
    static void (*GetCopyFunction(NiAnimationKey::KeyType))(
        NiAnimationKey *, const NiAnimationKey *
    );
    static NiAnimationKey *(*GetArrayFunction(NiAnimationKey::KeyType))(unsigned int);
    static void (*GetDeleteFunction(NiAnimationKey::KeyType))(NiAnimationKey *);
    static bool (*GetInsertFunction(NiAnimationKey::KeyType))(
        float, NiAnimationKey *&, unsigned int &
    );
    static void SetDefault(const NiColorA &);

protected:
    void LoadBinary(NiStream &);
    NiColorKey(float, const NiColorA &);

    NiColorA m_Color; // 0x4
    static NiColorA ms_kDefault;

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
    static NiColorA GenInterpDefault(
        float, NiColorKey *, NiAnimationKey::KeyType, unsigned int, unsigned char
    );
};
