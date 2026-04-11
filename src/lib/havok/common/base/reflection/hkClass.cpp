#include "hkclass.h"
#include "container/string/hkstring.h"
#include "reflection/hkclassenum.h"
#include "reflection/hkclassmember.h"

const char *hkClass::getName() const { return m_name; }

const hkClass *hkClass::getParent() const { return m_parent; }

hkClass *hkClass::getParent() { return const_cast<hkClass *>(m_parent); }

int hkClass::getInheritanceDepth() const {
    int i = 0;
    const hkClass *cls = this;
    while (cls != nullptr) {
        i++;
        cls = cls->getParent();
    }
    return i;
}

hkBool hkClass::isSuperClass(const hkClass &super) const {
    const hkClass *other = &super;
    while (other != nullptr) {
        if (hkString::strCmp(other->m_name, m_name) == 0) {
            return true;
        }
        other = other->getParent();
    }
    return false;
}

int hkClass::getNumInterfaces() const {
    int total_ifaces = m_numImplementedInterfaces;
    const hkClass *cls = m_parent;
    while (cls != nullptr) {
        total_ifaces += cls->m_numImplementedInterfaces;
        cls = cls->getParent();
    }
    return total_ifaces;
}

const hkClass *hkClass::getInterface(int) const { return nullptr; }

const hkClass *hkClass::getDeclaredInterface(int) const { return nullptr; }

int hkClass::getNumDeclaredInterfaces() const { return m_numImplementedInterfaces; }

int hkClass::getNumEnums() const {
    int total_enums = m_numDeclaredEnums;
    const hkClass *cls = m_parent;
    while (cls != nullptr) {
        total_enums += cls->m_numDeclaredEnums;
        cls = cls->getParent();
    }
    return total_enums;
}

const hkClassEnum &hkClass::getEnum(int enumIndex) const {
    const int num_enums = getNumEnums();
    const hkClass *cls = this;
    int current_count = enumIndex - num_enums;
    do {
        current_count += cls->m_numDeclaredEnums;
        if (current_count >= 0)
            break;
        cls = cls->getParent();
        if (cls != nullptr)
            continue;
        return *m_declaredEnums;
    } while (current_count < 0);
    return cls->m_declaredEnums[current_count];
}

const hkClassEnum *hkClass::getEnumByName(const char *name) const {
    const hkClass *cls = this;
    for (int i = 0; i < getNumEnums(); i++) {
        const hkClassEnum &e = getEnum(i);
        if (hkString::strCmp(e.getName(), name) == 0) {
            return &e;
        }
    }
    return nullptr;
}

const hkClassEnum &hkClass::getDeclaredEnum(int enumIndex) const {
    return m_declaredEnums[enumIndex];
}

int hkClass::getNumDeclaredEnums() const { return m_numDeclaredEnums; }

int hkClass::getNumMembers() const {
    int total_members = m_numDeclaredMembers;
    const hkClass *cls = m_parent;
    while (cls != nullptr) {
        total_members += cls->m_numDeclaredMembers;
        cls = cls->getParent();
    }
    return total_members;
}

const hkClassMember &hkClass::getMember(int memberIndex) const {
    const int num_members = getNumMembers();
    const hkClass *cls = this;
    int current_count = memberIndex - num_members;
    do {
        current_count += cls->m_numDeclaredMembers;
        if (current_count >= 0)
            break;
        cls = cls->getParent();
        if (cls != nullptr)
            continue;
        return *m_declaredMembers;
    } while (current_count < 0);
    return cls->m_declaredMembers[current_count];
}

hkClassMember &hkClass::getMember(int memberIndex) {
    return const_cast<hkClassMember &>(
        const_cast<const hkClass *>(this)->getMember(memberIndex)
    );
}

int hkClass::getNumDeclaredMembers() const { return m_numDeclaredMembers; }

const hkClassMember &hkClass::getDeclaredMember(int memberIndex) const {
    return m_declaredMembers[memberIndex];
}

const hkClassMember *hkClass::getDeclaredMemberByName(const char *name) const {
    for (int i = 0; i < m_numDeclaredMembers; i++) {
        const hkClassMember *ptr = m_declaredMembers + i;
        if (hkString::strCmp(ptr->getName(), name) == 0) {
            return ptr;
        }
    }
    return nullptr;
}

const hkClassMember *hkClass::getMemberByName(const char *name) const {
    for (int i = 0; i < getNumMembers(); i++) {
        const hkClassMember &m = getMember(i);
        if (hkString::strCmp(m.getName(), name) == 0) {
            return &m;
        }
    }
    return nullptr;
}

int hkClass::getMemberIndexByName(char const *name) const {
    for (int i = 0; i < getNumMembers(); i++) {
        const hkClassMember &m = getMember(i);
        if (hkString::strCmp(m.getName(), name) == 0) {
            return i;
        }
    }
    return -1;
}

int hkClass::getDeclaredMemberIndexByName(char const *name) const {
    for (int i = 0; i < m_numDeclaredMembers; i++) {
        const hkClassMember &m = m_declaredMembers[i];
        if (hkString::strCmp(m.getName(), name) == 0) {
            return i;
        }
    }
    return -1;
}

int hkClass::getObjectSize() const { return m_objectSize; }

void hkClass::setObjectSize(int size) { m_objectSize = size; }

hkBool hkClass::hasVtable() const {
    const hkClass *r4 = this;
    const hkClass *cls = m_parent;
    while (cls != nullptr) { // this should be cmpwi
        // which is fucking weird. allegedly pointer reuse can solve it
        r4 = cls;
        cls = cls->getParent();
    }
    return r4->m_numImplementedInterfaces != 0;
}

int hkClass::getDescribedVersion() const { return m_describedVersion; }

hkResult hkClass::retrieveMember(
    int memberIndex, const void *&defaultOut, const hkClassMember *&memberOut
) const {
    const int num_members = getNumMembers();
    const hkClass *cls = this;
    int current_count = memberIndex - num_members;
    do {
        current_count += cls->m_numDeclaredMembers;
        if (current_count >= 0)
            break;
        cls = cls->getParent();
        if (cls != nullptr)
            continue;
        return HK_FAILURE;
    } while (current_count < 0);

    const void **defaults = (const void **)cls->m_defaults;
    if (defaults == nullptr) {
        return HK_FAILURE;
    }
    int offset = (int)defaults[current_count];
    if (offset < 0) {
        return HK_FAILURE;
    }
    defaultOut = offset + (const u8 *)defaults;
    memberOut = &cls->m_declaredMembers[offset];
    return HK_SUCCESS;
}

int hkClass::hasDefault(int memberIndex) const {
    const void *default_;
    const hkClassMember *member;
    return retrieveMember(memberIndex, default_, member) == HK_SUCCESS;
}

int hkClass::hasDeclaredDefault(int declaredIndex) const {
    const int *defaults = (const int *)m_defaults;
    if (defaults != nullptr) {
        int offset = defaults[declaredIndex];
        if (offset >= 0) {
            return true;
        }
    }
    return false;
}

const hkVariant *hkClass::getAttribute(const char *name) const {
    if (m_attributes != nullptr) {
        return m_attributes->getAttribute(name);
    }
    return nullptr;
}

const hkFlags<hkClass::FlagValues, uint> &hkClass::getFlags(void) const {
    return m_flags;
}

hkFlags<hkClass::FlagValues, uint> &hkClass::getFlags(void) { return m_flags; }

hkClass::hkClass(
    const char *className,
    const hkClass *parentClass,
    int objectSizeInBytes,
    const hkClass **implementedInterfaces,
    int numImplementedInterfaces,
    const hkClassEnum *declaredEnums,
    int numDeclaredEnums,
    const hkClassMember *declaredMembers,
    int numDeclaredMembers,
    const void *defaults,
    const hkCustomAttributes *attributes,
    uint flags,
    uint describedVersion
)
    : m_numImplementedInterfaces(numImplementedInterfaces),
      m_declaredEnums(declaredEnums), m_numDeclaredEnums(numDeclaredEnums),
      m_objectSize(objectSizeInBytes), m_name(className), m_parent(parentClass),
      m_declaredMembers(declaredMembers), m_numDeclaredMembers(numDeclaredMembers),
      m_defaults(defaults), m_attributes(attributes), m_flags(flags),
      m_describedVersion(describedVersion) {}

const hkClassEnum *hkClass::getDeclaredEnumByName(const char *name) const {
    for (int i = 0; i < m_numDeclaredEnums; i++) {
        const hkClassEnum *ptr = &m_declaredEnums[i];
        if (hkString::strCmp(ptr->getName(), name) == 0) {
            return ptr;
        }
    }
    return nullptr;
}

uint hkClass::getSignature(int signatureFlags) const { return 0; }
