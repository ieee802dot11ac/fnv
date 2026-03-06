#pragma once

#include "hkdefs.h"
#include <types.h>
#include "types/hkbasetypes.h"

class hkString {
public:
    enum ReplaceType {
        REPLACE_ONE = 0x0000,
        REPLACE_ALL = 0x0001,
    };

    void iShouldNotHaveVtable() const;
    hkString(const hkString &);
    hkString(const char *, int);
    hkString(const char *);
    hkString();
    hkString &operator=(const char *);
    hkString &operator=(const hkString &);
    ~hkString();
    char operator[](int) const;
    void setCapacity(int);
    int getCapacity() const;
    // const hkArray<char>& getArray() const;
    void printf(const char *, ...);
    int indexOf(char, int, int) const;
    int lastIndexOf(char, int, int) const;
    const char *cString() const;
    int compareTo(const char *) const;
    int compareTo(const hkString &) const;
    int compareToIgnoreCase(const char *) const;
    int compareToIgnoreCase(const hkString &) const;
    hkBool operator<(const hkString &) const;
    hkBool operator==(const char *) const;
    hkBool operator==(const hkString &) const;
    hkBool operator!=(const char *) const;
    hkBool operator!=(const hkString &) const;
    hkBool beginsWith(const char *) const;
    hkBool beginsWith(const hkString &) const;
    hkBool endsWith(const char *) const;
    hkBool endsWith(const hkString &) const;
    hkString operator+(const char *) const;
    hkString operator+(const hkString &) const;
    hkString &operator+=(const char *);
    hkString &operator+=(const hkString &);
    int getLength() const;
    hkString replace(const hkString &, const hkString &, ReplaceType) const;
    hkString replace(char, char, ReplaceType) const;
    hkBool replaceInplace(const hkString &, const hkString &, ReplaceType);
    hkBool replaceInplace(char, char, ReplaceType);
    hkString asUpperCase() const;
    void makeUpperCase();
    hkString asLowerCase() const;
    void makeLowerCase();
    hkString substr(int, int) const;
    void setAsSubstr(int, int);
    //   void split(int, hkObjectArray<hkString>&) const;

    static char toUpper(char);
    static char toLower(char);
    static int snprintf(char *, int, const char *, ...);
    static int vsnprintf(char *, int, const char *, void *);
    static int sprintf(char *, const char *, ...);
    static int strCmp(const char *, const char *);
    static int strNcmp(const char *, const char *, int);
    static int strCasecmp(const char *, const char *);
    static int strNcasecmp(const char *, const char *, int);
    static void strCpy(char *, const char *);
    static void strNcpy(char *, const char *, int);
    static int strLen(const char *);
    static int atoi(const char *, int);
    static float atof(const char *);
    static const char *strStr(const char *, const char *);
    // static hkBool
    // findAllOccurrences(const char *, const char *, hkArray<int> &, ReplaceType);
    static const char *strChr(const char *, int);
    static const char *strRchr(const char *, int);
    static char *strDup(const char *);
    static char *strNdup(const char *, int);
    static char *strLwr(char *);
    static char *strUpr(char *);
    static void memCpy(void *, const void *, int);
    static void memCpy4(void *, const void *, int);
    static void memCpy16(void *, const void *, int);
    static void memCpy16NonEmpty(void *, const void *, int);
    static void memCpy128(void *, const void *);
    static void memCpy256(void *, const void *);
    static void memMove(void *, const void *, int);
    static void memSet(void *, const int, int);
    static void memSet4(void *, const int, int);
    static void memClear16(void *, int);
    static void memSet16(void *, const void *, int);
    static int memCmp(const void *, const void *, int);

    HKMEMOPS_ARR
private:
    // static void copyAndReplace(
    //     char *,
    //     const char *,
    //     int,
    //     const hkString &,
    //     const hkString &,
    //     const hkArray<int> &
    // );
    hkString(char *, int, int);
    void setLength(int);
    // hkArray<char> m_string; // 0x0
};
