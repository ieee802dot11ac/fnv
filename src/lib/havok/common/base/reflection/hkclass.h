#pragma once

#include <types.h>
#include "hkclassenum.h"
#include "hkclassmember.h"
#include "types/hkbasetypes.h"

// type info is just. missing. for hkClass. no clue why! but it is!
// fwiw i think typeinfo for havok is just kinda fucked six ways from sunday
// so this one is stolen from amped 3 :3
class hkClass { /* Size=0x24 */
public:
    static const hkInternalClassMember Members[0];

    hkClass(const char *, const hkClass *, int32_t, const hkClass **, int32_t, const hkClassEnum *, int32_t, const hkClassMember *, int32_t, const void *);
    const char *getName() const;
    hkClass *getParent();
    const hkClass *getParent() const;
    int32_t getInheritanceDepth() const;
    hkBool isSuperClass(const hkClass &) const;
    const hkClass *getInterface(int32_t) const;
    int32_t getNumInterfaces() const;
    const hkClass *getDeclaredInterface(int32_t) const;
    int32_t getNumDeclaredInterfaces() const;
    const hkClassEnum &getEnum(int32_t) const;
    const hkClassEnum *getEnumByName(const char *) const;
    int32_t getNumEnums() const;
    hkClassMember &getMember(int32_t);
    const hkClassMember &getMember(int32_t) const;
    int32_t getNumMembers() const;
    const hkClassMember &getDeclaredMember(int32_t) const;
    int32_t getNumDeclaredMembers() const;
    const hkClassMember *getMemberByName(const char *) const;
    int32_t getObjectSize() const;
    void setObjectSize(int32_t);
    hkBool hasVtable() const;
    // hkResult getDefault(int32_t, hkStreamWriter *) const;
    uint32_t getSignature() const;
    // void write(hkStreamWriter *) const;

    HKMEMOPS_ARR
protected:
    const char *m_name; // 0x00
    const hkClass *m_parent; // 0x04
    int32_t m_objectSize; // 0x08
    int32_t m_numImplementedInterfaces; // 0x0c
    const hkClassEnum *m_declaredEnums; // 0x10
    int32_t m_numDeclaredEnums; // 0x14
    const hkClassMember *m_declaredMembers; // 0x18
    int32_t m_numDeclaredMembers; // 0x1c
    const void *m_defaults; // 0x20
};
