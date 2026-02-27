#pragma once

class hkBool {
private:
    char m_bool; // 0x0

public:
    hkBool(bool);
    hkBool();
    operator bool() const;
    hkBool operator==(bool) const;
    hkBool operator!=(bool) const;
};

template <typename E, typename Size>
class hkEnum {
public:
    hkEnum(E enumerator) : m_storage(enumerator) {}
    hkEnum() : m_storage(0) {}
    operator E() const { return static_cast<E>(m_storage); }
    hkBool operator==(E enumerator) const { return m_storage == enumerator; }
    hkBool operator!=(E enumerator) const { return m_storage != enumerator; }

private:
    Size m_storage;
};

template <typename E, typename Size>
class hkFlags {
public:
    hkFlags(Size enumerator) : m_storage(enumerator) {}
    hkFlags() : m_storage() {}
    void clear() { m_storage = 0; }
    void setAll(Size bitset) { m_storage = bitset; }
    void orWith(Size bitset) { m_storage |= bitset; }
    void xorWith(Size bitset) { m_storage ^= bitset; }
    void andWith(Size bitset) { m_storage &= bitset; }
    // void setWithMask(Size, Size); // might not exist
    Size get(Size flag) const { return m_storage & flag; }
    Size get() const { return m_storage; }
    bool anyIsSet(Size flags) const { return m_storage & flags; }
    bool allAreSet(Size flags) const { return (m_storage & flags) == flags; }
    bool operator==(const hkFlags<E, Size> &rhs) const {
        return m_storage == rhs.m_storage;
    }
    bool operator!=(const hkFlags<E, Size> &rhs) const {
        return m_storage != rhs.m_storage;
    }

private:
    Size m_storage;
};

// iunno where this is sposed to go so here
struct hkVariant { /* Size=0x8 */
    void *m_object; // 0x0
    const class hkClass *m_class; // 0x4
};
