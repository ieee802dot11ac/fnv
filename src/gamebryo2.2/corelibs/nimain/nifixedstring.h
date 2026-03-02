#pragma once

#include <types.h>

class NiFixedString {
public: // TODO: most of these are defined in nifixedstring.inl
    NiFixedString(const NiFixedString &);
    NiFixedString(const char *);
    NiFixedString();
    ~NiFixedString();
    operator const char *() const;
    bool Exists() const;
    NiFixedString &operator=(const char *);
    NiFixedString &operator=(const NiFixedString &);
    uint32_t GetLength() const;
    uint32_t GetRefCount() const;
    bool Equals(const char *) const;
    bool EqualsNoCase(const char *) const;
    bool Contains(const char *) const;
    bool ContainsNoCase(const char *) const;
    uint32_t QHandle() const;
    void Init();

protected:
    char *m_kHandle; // 0x0
};
