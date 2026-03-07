#pragma once

#include "nimain/nitarray.h"
#include <types.h>

union SETTING_VALUE { /* Size=0x4 */
    const char *str;
    int i;
    uint u;
    float f;
    bool b;
    s8 c;
    u8 h;
};

class Setting { /* Size=0xc */
public:
    enum SETTING_TYPE {
        ST_BINARY = 0x0000,
        ST_CHAR = 0x0001,
        ST_UCHAR = 0x0002,
        ST_INT = 0x0003,
        ST_UINT = 0x0004,
        ST_FLOAT = 0x0005,
        ST_STRING = 0x0006,
        ST_RGB = 0x0007,
        ST_RGBA = 0x0008,
        ST_NONE = 0x0009,
    };
    SETTING_VALUE uValue; // 0x4
    const char *pKey; // 0x8

    Setting(const Setting &);
    Setting(const char *, u8);
    Setting(const char *, s8);
    Setting(const char *, bool);
    Setting(const char *, float);
    Setting(const char *, uint);
    Setting(const char *, int);
    Setting(const char *, char *);
    Setting(const char *, SETTING_VALUE);
    virtual ~Setting();
    const char *String();
    int &Int();
    uint &UInt();
    float &Float();
    bool &Bool();
    s8 &Char();
    u8 &UChar();
    const char *Key();
    Setting &operator=(const Setting &);
    Setting &operator=(const u8);
    Setting &operator=(const s8);
    Setting &operator=(const bool);
    Setting &operator=(const float);
    Setting &operator=(const uint);
    Setting &operator=(const int);
    Setting &operator=(const char *);
    Setting &operator=(const SETTING_VALUE);
    operator bool();
    operator int();
    operator unsigned int();
    operator float();
    operator const char *();
    operator s8();
    operator u8();
    int operator==(const char *) const;
    bool operator==(u8) const;
    bool operator==(s8) const;
    bool operator==(float) const;
    bool operator==(uint) const;
    bool operator==(int) const;
    bool operator==(bool) const;
    bool operator==(Setting &) const;
    bool operator!=(u8) const;
    bool operator!=(s8) const;
    bool operator!=(float) const;
    bool operator!=(uint) const;
    bool operator!=(int) const;
    bool operator!=(bool) const;
    bool operator!=(Setting &) const;
    uint AND(uint) const;
    bool operator!() const;
    void GetViewerStrings(NiTPrimitiveArray<char *> *);
    uint DataSize();
    SETTING_TYPE DataType();
    virtual bool IsPrefSetting();

    static SETTING_TYPE DataType(const char *);

protected:
    static SETTING_VALUE stdef;
};

template <typename T>
class SettingT : public Setting {
public:
    SettingT<T>(const SettingT<T> &);
    SettingT<T>(const char *, u8);
    SettingT<T>(const char *, s8);
    SettingT<T>(const char *, bool);
    SettingT<T>(const char *, float);
    SettingT<T>(const char *, uint);
    SettingT<T>(const char *, int);
    SettingT<T>(const char *, char *);
    SettingT<T>(const char *, SETTING_VALUE);
    virtual ~SettingT<T>();
    SettingT<T> &operator=(const SettingT<T> &);
    SettingT<T> &operator=(const u8);
    SettingT<T> &operator=(const s8);
    SettingT<T> &operator=(const bool);
    SettingT<T> &operator=(const float);
    SettingT<T> &operator=(const uint);
    SettingT<T> &operator=(const int);
    SettingT<T> &operator=(const char *);
    SettingT<T> &operator=(const SETTING_VALUE);
    int operator==(const char *) const;
    bool operator==(u8) const;
    bool operator==(s8) const;
    bool operator==(float) const;
    bool operator==(uint) const;
    bool operator==(int) const;
    bool operator==(bool) const;
    bool operator==(SettingT<T> &) const;
    bool operator!=(u8) const;
    bool operator!=(s8) const;
    bool operator!=(float) const;
    bool operator!=(uint) const;
    bool operator!=(int) const;
    bool operator!=(bool) const;
    bool operator!=(SettingT<T> &) const;
    uint operator&(uint) const;
    bool operator!() const;

    static T &QCollection();

protected:
    static void InitCollection();
    static T *pCollection;
};
