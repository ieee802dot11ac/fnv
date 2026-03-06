#pragma once

#include "hkdefs.h"
#include "reflection/attributes/hkattributes.h"
#include "types/hkbasetypes.h"
#include <types.h>
#include "reflection/hkinternalclassmember.h"

class hkClass;

enum hkResult : int32_t {
    HK_SUCCESS = 0x0000,
    HK_FAILURE = 0x0001,
};

class hkClassEnum {
public:
    enum FlagValues {
        FLAGS_NONE = 0x0000,
    };

    class Item {
    public:
        Item(int32_t, const char *);
        const char *getName() const;
        int32_t getValue() const;

        static const hkInternalClassMember Members[0];
        HKMEMOPS_ARR

    private:
        int32_t m_value; // 0x0
        const char *m_name; // 0x4
    };

    hkClassEnum(const char *, const hkClassEnum::Item *, int32_t);
    const char *getName() const { return m_name; }
    int32_t getNumItems() const;
    const hkClassEnum::Item &getItem(int32_t) const;
    hkResult getNameOfValue(int32_t, const char **) const;
    hkResult getValueOfName(const char *, int32_t *) const;

private:
    const char *m_name; // 0x0
    const hkClassEnum::Item *m_items; // 0x4
    int32_t m_numItems; // 0x8
    hkCustomAttributes *m_attributes; // 0xc
    hkFlags<FlagValues, uint> m_flags; // 0x10
public:
    static const hkInternalClassMember Members[0];
    HKMEMOPS_ARR
};
