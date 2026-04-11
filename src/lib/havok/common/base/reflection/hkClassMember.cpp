#include "hkclassmember.h"
#include "hkclass.h"

static hkClassMember::TypeProperties ClassMemberProperties[33];

const hkClassMember::TypeProperties &
hkClassMember::getClassMemberTypeProperties(hkClassMember::Type type) {
    return ClassMemberProperties[type];
}

const hkClass &hkClassMember::getStructClass() const { return *m_class; }

const hkClass *hkClassMember::getClass() const { return m_class; }

const hkClassEnum &hkClassMember::getEnumClass() const { return *m_enum; }

int hkClassMember::getCstyleArraySize(void) const { return m_cArraySize; }

const hkClassEnum &hkClassMember::getEnumType() const { return *m_enum; }

const hkVariant *hkClassMember::getAttribute(const char *name) const {
    if (m_attributes) {
        return m_attributes->getAttribute(name);
    }
    return nullptr;
}

int hkClassMember::getSizeInBytes() const {
    int siz = -1;
    switch (m_type) {
    case TYPE_BOOL:
    case TYPE_CHAR:
    case TYPE_INT8:
    case TYPE_UINT8:
    case TYPE_INT16:
    case TYPE_UINT16:
    case TYPE_INT32:
    case TYPE_UINT32:
    case TYPE_INT64:
    case TYPE_UINT64:
    case TYPE_REAL:
    case TYPE_VECTOR4:
    case TYPE_QUATERNION:
    case TYPE_MATRIX3:
    case TYPE_ROTATION:
    case TYPE_QSTRANSFORM:
    case TYPE_MATRIX4:
    case TYPE_TRANSFORM:
    case TYPE_POINTER:
    case TYPE_FUNCTIONPOINTER:
    case TYPE_ARRAY:
    case TYPE_SIMPLEARRAY:
    case TYPE_HOMOGENEOUSARRAY:
    case TYPE_VARIANT:
    case TYPE_CSTRING:
    case TYPE_ULONG:
    case TYPE_MAX:
    case TYPE_MAX + 1: { // what?
        int count = m_cArraySize == 0 ? 1 : m_cArraySize;
        siz = ClassMemberProperties[m_type].m_size * count;
    } break;
    case TYPE_ENUM:
    case TYPE_FLAGS: {
        int count = m_cArraySize == 0 ? 1 : m_cArraySize;
        siz = ClassMemberProperties[m_subtype].m_size * count;
    } break;
    case TYPE_STRUCT: {
        int count = m_cArraySize == 0 ? 1 : m_cArraySize;
        siz = m_class->getObjectSize() * count;
    } break;
    case TYPE_ZERO:
    case TYPE_INPLACEARRAY: {
    }
    }
    return siz;
}

hkBool hkClassMember::isNotOwner() const { return m_flags.get(NOT_OWNED); }

int hkClassMember::getAlignment() const { return 0; }

hkClassMember::Type hkClassMember::getArrayType() const { return m_subtype; }

int hkClassMember::getArrayMemberSize() const {
    uint v = m_subtype;
    if (v != TYPE_ENUM && v != TYPE_FLAGS) {
        if (v != TYPE_STRUCT) {
            return ClassMemberProperties[m_subtype].m_size;
        } else {
            return m_class->getObjectSize();
        }
    }
    return -1;
}

int hkClassMember::getEnumValue(const void *memberAddress) const {
    int val = 0;
    switch (getSizeInBytes()) {
    case 1:
        val = *(const s8 *)memberAddress;
        break;
    case 2:
        val = *(const s16 *)memberAddress;
        break;
    case 4:
        val = *(const u32 *)memberAddress;
        break;
    default:;
    }
    return val;
}

void hkClassMember::setEnumValue(void *memberAddress, int value) const {
    switch (getSizeInBytes()) {
    case 1: {
        s8 *ptr = (s8 *)memberAddress;
        *ptr = value;
    } break;
    case 2: {
        s16 *ptr = (s16 *)memberAddress;
        *ptr = value;
    } break;
    case 4: {
        u32 *ptr = (u32 *)memberAddress;
        *ptr = value;
    } break;
    default:;
    }
}

hkClassMember::Type hkClassMember::getTypeOf(const char *name) { return TYPE_VOID; }

hkClassMember::Type hkClassMember::getSubtypeOf(const char *name) { return TYPE_VOID; }
