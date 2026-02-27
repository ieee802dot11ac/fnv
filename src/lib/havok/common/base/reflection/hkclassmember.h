#pragma once
#include "hkdefs.h"
#include <types.h>
#include "types/hkbasetypes.h"
#include "hkinternalclassmember.h"
#include "reflection/attributes/hkattributes.h"

class hkClass;

class hkClassMember { /* Size=0x18 */

public:
    enum Type {
        TYPE_VOID = 0x0000,
        TYPE_BOOL = 0x0001,
        TYPE_CHAR = 0x0002,
        TYPE_INT8 = 0x0003,
        TYPE_UINT8 = 0x0004,
        TYPE_INT16 = 0x0005,
        TYPE_UINT16 = 0x0006,
        TYPE_INT32 = 0x0007,
        TYPE_UINT32 = 0x0008,
        TYPE_INT64 = 0x0009,
        TYPE_UINT64 = 0x000a,
        TYPE_REAL = 0x000b,
        TYPE_VECTOR4 = 0x000c,
        TYPE_QUATERNION = 0x000d,
        TYPE_MATRIX3 = 0x000e,
        TYPE_ROTATION = 0x000f,
        TYPE_QSTRANSFORM = 0x0010,
        TYPE_MATRIX4 = 0x0011,
        TYPE_TRANSFORM = 0x0012,
        TYPE_ZERO = 0x0013,
        TYPE_POINTER = 0x0014,
        TYPE_FUNCTIONPOINTER = 0x0015,
        TYPE_ARRAY = 0x0016,
        TYPE_INPLACEARRAY = 0x0017,
        TYPE_ENUM = 0x0018,
        TYPE_STRUCT = 0x0019,
        TYPE_SIMPLEARRAY = 0x001a,
        TYPE_HOMOGENEOUSARRAY = 0x001b,
        TYPE_VARIANT = 0x001c,
        TYPE_CSTRING = 0x001d,
        TYPE_ULONG = 0x001e,
        TYPE_FLAGS = 0x001f,
        TYPE_MAX = 0x0020,
    };

    enum FlagValues {
        FLAGS_NONE = 0x0000,
        ALIGN_8 = 0x0080,
        ALIGN_16 = 0x0100,
        NOT_OWNED = 0x0200,
        SERIALIZE_IGNORED = 0x0400,
    };

    struct TypeProperties { /* Size=0xc */
        hkEnum<enum hkClassMember::Type, unsigned char> m_type; // 0x0
        const char *m_name; // 0x4
        int16_t m_size; // 0x8
        int16_t m_align; // 0xa

        void iShouldNotHaveVtable() const;
        TypeProperties();

        HKMEMOPS_ARR
    };

    void iShouldNotHaveVtable() const;
    const char *getName() const;
    hkClassMember::Type getType() const;
    void setType(hkClassMember::Type);
    hkClassMember::Type getSubType() const;
    void setSubType(hkClassMember::Type);
    hkClassMember::Type getArrayType() const;
    int32_t getSizeInBytes() const;
    int32_t getAlignment() const;
    hkBool isNotOwner() const;
    int32_t getTypeName(char *, int32_t) const;
    int32_t getArrayMemberSize() const;
    hkBool hasClass() const;
    const hkClass &getStructClass() const;
    const hkClass *getClass() const;
    hkBool hasEnumClass() const;
    const hkClassEnum &getEnumClass() const;
    int32_t getCstyleArraySize() const;
    const hkClassEnum &getEnumType() const;
    int32_t getEnumValue(const void *) const;
    void setEnumValue(void *, int32_t) const;
    int32_t getOffset() const;
    void setOffset(int32_t);
    hkFlags<enum hkClassMember::FlagValues, unsigned short> &getFlags();
    const hkFlags<enum hkClassMember::FlagValues, unsigned short> &getFlags() const;
    const hkVariant *getAttribute(const char *) const;
    hkClassMember();

    HKMEMOPS_ARR
    static const hkClass &staticClass();
    static hkClassMember::Type getTypeOf(const char *);
    static hkClassMember::Type getSubtypeOf(const char *);
    static const hkClassMember::TypeProperties &
        getClassMemberTypeProperties(hkClassMember::Type);

    static const hkInternalClassMember Members[0];

private:
    const char *m_name; // 0x00
    const hkClass *m_class; // 0x04
    const hkClassEnum *m_enum; // 0x08
    hkEnum<enum hkClassMember::Type, unsigned char> m_type; // 0x0c
    hkEnum<enum hkClassMember::Type, unsigned char> m_subtype; // 0x0d
    int16_t m_cArraySize; // 0x0e
    hkFlags<enum hkClassMember::FlagValues, unsigned short> m_flags; // 0x10
    uint16_t m_offset; // 0x12
    const hkCustomAttributes *m_attributes; // 0x14
};
