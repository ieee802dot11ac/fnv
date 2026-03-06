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
    enum FlagValues {
        FLAGS_NONE = 0x0000,
        FLAGS_NOT_SERIALIZABLE = 0x0001,
    };
    static const hkInternalClassMember Members[0];

    hkClass(
        char const *,
        hkClass const *,
        int,
        hkClass const **,
        int,
        hkClassEnum const *,
        int,
        hkClassMember const *,
        int,
        void const *,
        hkCustomAttributes const *,
        unsigned int,
        unsigned int
    );
    const char *getName() const;
    hkClass *getParent();
    const hkClass *getParent() const;
    int getInheritanceDepth() const;
    hkBool isSuperClass(const hkClass &) const;
    const hkClass *getInterface(int) const;
    int getNumInterfaces() const;
    const hkClass *getDeclaredInterface(int) const;
    int getNumDeclaredInterfaces() const;
    const hkClassEnum &getEnum(int) const;
    const hkClassEnum *getEnumByName(const char *) const;
    int getNumEnums() const;
    const hkClassEnum &getDeclaredEnum(int) const;
    const hkClassEnum *getDeclaredEnumByName(char const *) const;
    int getNumDeclaredEnums() const;
    hkClassMember &getMember(int);
    const hkClassMember &getMember(int) const;
    int getNumMembers() const;
    const hkClassMember &getDeclaredMember(int) const;
    int getNumDeclaredMembers() const;
    const hkClassMember *getDeclaredMemberByName(const char *) const;
    const hkClassMember *getMemberByName(const char *) const;
    int getMemberIndexByName(char const *) const;
    int getDeclaredMemberIndexByName(char const *) const;
    int getObjectSize() const;
    void setObjectSize(int);
    hkBool hasVtable() const;

    int hasDefault(int memberIndex) const;
    int hasDeclaredDefault(int declaredIndex) const;

    const hkVariant *getAttribute(const char *) const;

    const hkFlags<FlagValues, uint> &getFlags(void) const;
    hkFlags<FlagValues, uint> &getFlags(void);

    int getDescribedVersion() const;
    // hkResult getDefault(int, hkStreamWriter *) const;
    uint getSignature(int) const;
    // void write(hkStreamWriter *) const;

    HKMEMOPS_ARR
protected:
    const char *m_name; // 0x00
    const hkClass *m_parent; // 0x04
    int m_objectSize; // 0x08
    int m_numImplementedInterfaces; // 0x0c
    const hkClassEnum *m_declaredEnums; // 0x10
    int m_numDeclaredEnums; // 0x14
    const hkClassMember *m_declaredMembers; // 0x18
    int m_numDeclaredMembers; // 0x1c
    const void *m_defaults; // 0x20
    const hkCustomAttributes *m_attributes; // 0x24
    hkFlags<FlagValues, uint> m_flags; // 0x28
    int m_describedVersion; // 0x2c

private:
    hkResult retrieveMember(int, const void *&, const hkClassMember *&) const;
};
