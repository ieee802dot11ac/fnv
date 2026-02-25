#pragma once

#include <types.h>

template <typename T>
class BSStringT {
public:
    BSStringT(const BSStringT<T> &);
    BSStringT(const T *);
    BSStringT();
    ~BSStringT();
    bool Set(const BSStringT<T> &);
    bool Set(const T *, uint);
    const T *String() const;
    uint ByteLength() const;
    uint ByteLengthWithNull() const;
    uint Length() const;
    uint MaxLength() const;
    void Fill(T);
    int VSPrintF(const T *, T *);
    int SPrintF(const T *, ...);
    int StrCmp(const BSStringT<T> &, bool) const;
    int StrCmp(const T *, bool) const;
    void MakeUpper();
    void MakeLower();
    BSStringT<T> &operator=(BSStringT<T> const &);
    BSStringT<T> &operator=(const T *);
    bool operator==(const BSStringT<T> &) const;
    bool operator==(const T *) const;
    bool operator!=(const BSStringT<T> &) const;
    bool operator!=(const T *) const;
    BSStringT<T> &operator+=(const BSStringT<T> &);
    BSStringT<T> &operator+=(const T *);
    T &operator[](uint);
    operator const T *() const;
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
