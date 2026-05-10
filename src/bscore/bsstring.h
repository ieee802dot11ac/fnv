#pragma once

#include <types.h>

template <typename T>
class BSStringT {
public:
    BSStringT(const BSStringT<T> &);
    BSStringT(const T *);
    BSStringT() : pString(nullptr), sLen(0), sMaxLen(0) {}
    ~BSStringT() { Set(nullptr, 0); }
    bool Set(const BSStringT<T> &rhs) {
        Set(rhs.String(), 0);
        return true;
    }
    bool Set(const T *, uint);
    const T *String() const { return int(pString) != 0 ? pString : ""; }
    uint ByteLength() const { return strlen(pString); }
    uint ByteLengthWithNull() const { return strlen(pString) + 1; }
    uint Length() const { return sLen; }
    uint MaxLength() const { return sMaxLen; }
    void Fill(T);
    int VSPrintF(const T *, T *);
    int SPrintF(const T *, ...);
    int StrCmp(const BSStringT<T> &, bool) const;
    int StrCmp(const T *, bool) const;
    void MakeUpper();
    void MakeLower();
    BSStringT<T> &operator=(BSStringT<T> const &rhs) {
        Set(rhs);
        return *this;
    }
    BSStringT<T> &operator=(const T *rhs) {
        Set(rhs, 0);
        return *this;
    }
    bool operator==(const BSStringT<T> &) const;
    bool operator==(const T *) const;
    bool operator!=(const BSStringT<T> &) const;
    bool operator!=(const T *) const;
    BSStringT<T> &operator+=(const BSStringT<T> &);
    BSStringT<T> &operator+=(const T *);
    T &operator[](uint);
    operator const T *() const { return pString; }
    BSStringT<T> RemoveCurlyContent();

protected:
    T *pString; // 0x0
    u16 sLen; // 0x4
    u16 sMaxLen; // 0x6
    void SetLength(uint);
    void SetMaxLength(uint);

private:
    void Init();
};
