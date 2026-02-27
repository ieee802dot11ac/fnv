#pragma once

#include "hkdefs.h"
#include <types.h>
#include "types/hkbasetypes.h"
#include "reflection/hkinternalclassmember.h"

class hkCustomAttributes { /* Size=0x8 */
public:
    struct Attribute { /* Size=0xc */
        const char *m_name; // 0x0
        hkVariant m_value; // 0x4
        static const hkInternalClassMember Members[0];

        void iShouldNotHaveVtable() const;

        static const hkClass &staticClass();
        HKMEMOPS_ARR
    };

    static const hkInternalClassMember Members[0];

    void iShouldNotHaveVtable() const;
    const hkVariant *getAttribute(const char *) const;

    HKMEMOPS_ARR

private:
    const Attribute *m_attributes; // 0x0
    int32_t m_numAttributes; // 0x4
};
