#pragma once
#include "hkdefs.h"
#include <types.h>

class hkClass;
class hkClassEnum;

// too lazy to find if there's a header for this in ds2 so it goes here
struct hkInternalCustomAttributes {
    struct Attribute {
        const char *m_name; // 0x0
        const void *m_data; // 0x4
        const hkClass *m_klass; // 0x8
    };
    const Attribute *m_attributes; // 0x0
    int32_t m_numAttributes; // 0x4

    HKMEMOPS
};

struct hkInternalClassMember {
    const char *m_name; // 0x00
    const hkClass *m_class; // 0x04
    const hkClassEnum *m_enum; // 0x08
    u8 m_type; // 0x0c
    u8 m_subtype; // 0x0d
    u16 m_cArraySize; // 0x0e
    u16 m_flags; // 0x10
    u16 m_offset; // 0x12
    const hkInternalCustomAttributes *m_attributes; // 0x14

    HKMEMOPS
};
