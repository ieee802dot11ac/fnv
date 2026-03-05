#pragma once

#include <types.h>
#include "nimain/nistream.h"

class NiAnimationKey {
public:
    enum KeyType {
        NOINTERP = 0x0000,
        LINKEY = 0x0001,
        BEZKEY = 0x0002,
        TCBKEY = 0x0003,
        EULERKEY = 0x0004,
        STEPKEY = 0x0005,
        NUMKEYTYPES = 0x0006,
    };

    enum KeyContent {
        FLOATKEY = 0x0000,
        POSKEY = 0x0001,
        ROTKEY = 0x0002,
        COLORKEY = 0x0003,
        TEXTKEY = 0x0004,
        BOOLKEY = 0x0005,
        NUMKEYCONTENTS = 0x0006,
    };

    ~NiAnimationKey();
    void SetTime(float);
    float GetTime() const;
    NiAnimationKey *GetKeyAt(uint32_t, unsigned char) const;

    static int32_t RegisterLoader();
    static void
        RegisterSupportedFunctions(NiAnimationKey::KeyContent, NiAnimationKey::KeyType);
    static unsigned char GetKeySize(NiAnimationKey::KeyContent, NiAnimationKey::KeyType);
    static float (*GetCurvatureFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        NiAnimationKey *, uint32_t
    );
    static void (*GetInterpFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        float, const NiAnimationKey *, const NiAnimationKey *, void *
    );
    static void (*GetInterpD1Function(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        float, const NiAnimationKey *, const NiAnimationKey *, void *
    );
    static void (*GetInterpD2Function(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        float, const NiAnimationKey *, const NiAnimationKey *, void *
    );
    static void (*GetFillDerivedFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        NiAnimationKey *, uint32_t, unsigned char
    );
    static NiAnimationKey
        *(*GetCreateFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
            NiStream &, uint32_t
        );
    static void (*GetSaveFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        NiStream &, NiAnimationKey *, uint32_t
    );
    static bool (*GetEqualFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        const NiAnimationKey &, const NiAnimationKey &
    );
    static void (*GetCopyFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        NiAnimationKey *, const NiAnimationKey *
    );
    static NiAnimationKey
        *(*GetArrayFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
            uint32_t
        );
    static void (*GetDeleteFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        NiAnimationKey *
    );
    static bool (*GetInsertFunction(NiAnimationKey::KeyContent, NiAnimationKey::KeyType))(
        float, NiAnimationKey *&, uint32_t &
    );
    static void CopySequence(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        const NiAnimationKey *,
        uint32_t,
        float,
        float,
        NiAnimationKey *&,
        uint32_t &
    );
    static void GuaranteeKeyAtStartAndEnd(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        NiAnimationKey *&,
        uint32_t &,
        float,
        float
    );
    static bool
    OkayToInsert(float, const NiAnimationKey *, uint32_t, uint32_t &, unsigned char);

protected:
    NiAnimationKey();
    NiAnimationKey(float);
    void LoadBinary(NiStream &);
    float m_fTime; // 0x0

    static NiAnimationKey *CreateFromStream(NiStream &, uint32_t);
    static void SaveToStream(NiStream &, NiAnimationKey *, uint32_t);
    static void SaveBinary(NiStream &, NiAnimationKey *);
    static void Copy(NiAnimationKey *, const NiAnimationKey *);
    static NiAnimationKey *CreateArray(uint32_t);
    static void DeleteArray(NiAnimationKey *);
    static bool Insert(float, NiAnimationKey *&, uint32_t &);
    static float ComputeMaxCurvature(NiAnimationKey *, uint32_t);
    static void
    Interpolate(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static void
    InterpolateD1(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static void
    InterpolateD2(float, const NiAnimationKey *, const NiAnimationKey *, void *);
    static bool Equal(const NiAnimationKey &, const NiAnimationKey &);
    static void FillDerivedVals(NiAnimationKey *, uint32_t, unsigned char);
    static void SetCreateFunction(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        NiAnimationKey *(*)(NiStream &, uint32_t)
    );
    static void SetCurvatureFunction(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        float (*)(NiAnimationKey *, uint32_t)
    );
    static void SetInterpFunction(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        void (*)(float, const NiAnimationKey *, const NiAnimationKey *, void *)
    );
    static void SetInterpD1Function(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        void (*)(float, const NiAnimationKey *, const NiAnimationKey *, void *)
    );
    static void SetInterpD2Function(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        void (*)(float, const NiAnimationKey *, const NiAnimationKey *, void *)
    );
    static void SetEqualFunction(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        bool (*)(const NiAnimationKey &, const NiAnimationKey &)
    );
    static void SetCopyFunction(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        void (*)(NiAnimationKey *, const NiAnimationKey *)
    );
    static void SetArrayFunction(
        NiAnimationKey::KeyContent, NiAnimationKey::KeyType, NiAnimationKey *(*)(uint32_t)
    );
    static void SetDeleteFunction(
        NiAnimationKey::KeyContent, NiAnimationKey::KeyType, void (*)(NiAnimationKey *)
    );
    static void SetInsertFunction(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        bool (*)(float, NiAnimationKey *&, uint32_t &)
    );
    static void SetSaveFunction(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        void (*)(NiStream &, NiAnimationKey *, uint32_t)
    );
    static void SetFillDerivedValsFunction(
        NiAnimationKey::KeyContent,
        NiAnimationKey::KeyType,
        void (*)(NiAnimationKey *, uint32_t, unsigned char)
    );
    static void
    SetKeySize(NiAnimationKey::KeyContent, NiAnimationKey::KeyType, unsigned char);

    static NiAnimationKey *(*ms_loaders[36])(NiStream &, uint32_t);
    static float (*ms_curves[36])(NiAnimationKey *, uint32_t);
    static void (*ms_interps[36])(
        float, const NiAnimationKey *, const NiAnimationKey *, void *
    );
    static void (*ms_interpd1s[36])(
        float, const NiAnimationKey *, const NiAnimationKey *, void *
    );
    static void (*ms_interpd2s[36])(
        float, const NiAnimationKey *, const NiAnimationKey *, void *
    );
    static bool (*ms_equals[36])(const NiAnimationKey &, const NiAnimationKey &);
    static void (*ms_copies[36])(NiAnimationKey *, const NiAnimationKey *);
    static NiAnimationKey *(*ms_arrays[36])(uint32_t);
    static void (*ms_deletes[36])(NiAnimationKey *);
    static bool (*ms_inserts[36])(float, NiAnimationKey *&, uint32_t &);
    static void (*ms_saves[36])(NiStream &, NiAnimationKey *, uint32_t);
    static void (*ms_fillderived[36])(NiAnimationKey *, uint32_t, unsigned char);
    static unsigned char ms_keysizes[36];
};
