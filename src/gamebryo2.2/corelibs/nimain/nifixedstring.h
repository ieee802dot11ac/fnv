#pragma once

#include "nimain/niglobalstringtable.h"
#include <types.h>

class NiFixedString {
public: // TODO: most of these are defined in nifixedstring.inl
    NiFixedString(const NiFixedString &);
    NiFixedString(const char *);
    NiFixedString() { m_kHandle = NiGlobalStringTable::NULL_STRING; }
    ~NiFixedString() {
        if (m_kHandle != NiGlobalStringTable::NULL_STRING)
            ;
    }
    operator const char *() const { return m_kHandle; }
    bool Exists() const;
    NiFixedString &operator=(const char *);
    NiFixedString &operator=(const NiFixedString &);
    uint32_t GetLength() const;
    uint32_t GetRefCount() const;
    bool operator!=(const char *other) { return m_kHandle != other; }
    bool operator!=(const NiFixedString &other) { return m_kHandle != other.m_kHandle; }
    bool EqualsNoCase(const char *) const;
    bool Contains(const char *) const;
    bool ContainsNoCase(const char *) const;
    uint32_t QHandle() const;
    void Init();

protected:
    char *m_kHandle; // 0x0
};
