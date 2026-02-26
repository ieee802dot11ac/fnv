#include "niobject.h"
#include <cstring>

NiObject::NiObject() {}

NiObject::~NiObject() {}

const NiRTTI *NiObject::GetStreamableRTTI() const { return GetRTTI(); }

bool NiObject::IsEqual(NiObject *other) {
    if (other == nullptr) {
        return false;
    } else {
        const char *their_name = other->GetRTTI()->GetName();
        const char *my_name = GetRTTI()->GetName();
        if (std::strcmp(my_name, their_name)) {
            return false;
        } else
            return true;
    }
}
