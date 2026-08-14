#pragma once

#include "bscore/memorymanager.h"
#include "bsmain/BSTCaseInsensitiveStringMap.h"
#include "nimain/nitarray.h"
#include <types.h>

#define SETTING(type, name, value) SettingT<type> name(#name, value);

union SETTING_VALUE { /* Size=0x4 */
	const char* str;
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
	const char* pKey;	  // 0x8

	Setting(const Setting&);
	Setting(const char* apKey, u8 aValue) {
		pKey = apKey;
		uValue.h = aValue;
	}
	Setting(const char* apKey, s8 aValue) {
		pKey = apKey;
		uValue.c = aValue;
	}
	Setting(const char* apKey, bool aValue) {
		pKey = apKey;
		uValue.b = aValue;
	}
	Setting(const char* apKey, float aValue) {
		pKey = apKey;
		uValue.f = aValue;
	}
	Setting(const char* apKey, uint aValue) {
		pKey = apKey;
		uValue.u = aValue;
	}
	Setting(const char* apKey, int aValue) {
		pKey = apKey;
		uValue.i = aValue;
	}
	Setting(const char* apKey, char* aValue) {
		pKey = apKey;
		uValue.str = aValue;
	}
	Setting(const char* apKey, SETTING_VALUE aValue) {
		pKey = apKey;
		uValue = aValue;
	}
	virtual ~Setting();
	const char* String() { return uValue.str; }
	int& Int() { return uValue.i; }
	uint& UInt();
	float& Float() { return uValue.f; }
	bool& Bool();
	s8& Char();
	u8& UChar();
	const char* Key();
	Setting& operator=(const Setting&);
	Setting& operator=(const u8);
	Setting& operator=(const s8);
	Setting& operator=(const bool);
	Setting& operator=(const float);
	Setting& operator=(const uint);
	Setting& operator=(const int);
	Setting& operator=(const char*);
	Setting& operator=(const SETTING_VALUE);
	operator bool();
	operator int();
	operator unsigned int();
	operator float();
	operator const char*();
	operator s8();
	operator u8();
	int operator==(const char*) const;
	bool operator==(u8) const;
	bool operator==(s8) const;
	bool operator==(float) const;
	bool operator==(uint) const;
	bool operator==(int) const;
	bool operator==(bool) const;
	bool operator==(Setting&) const;
	bool operator!=(u8) const;
	bool operator!=(s8) const;
	bool operator!=(float) const;
	bool operator!=(uint) const;
	bool operator!=(int) const;
	bool operator!=(bool) const;
	bool operator!=(Setting&) const;
	uint AND(uint) const;
	bool operator!() const;
	void GetViewerStrings(NiTPrimitiveArray<char*>*);
	uint DataSize();
	SETTING_TYPE DataType();
	virtual bool IsPrefSetting();

	static SETTING_TYPE DataType(const char*);

	BS_MEM_OVERLOADS

  protected:
	static SETTING_VALUE stdef;
};

template <typename T> class SettingT : public Setting {
  public:
	SettingT<T>(const SettingT<T>&);
	SettingT<T>(const char* apKey, u8 aValue) : Setting(apKey, aValue) {
		InitCollection();
		QCollection().Add(this);
	}
	SettingT<T>(const char* apKey, s8 aValue) : Setting(apKey, aValue) {
		InitCollection();
		QCollection().Add(this);
	}
	SettingT<T>(const char* apKey, bool aValue) : Setting(apKey, aValue) {
		InitCollection();
		QCollection().Add(this);
	}
	SettingT<T>(const char* apKey, float aValue) : Setting(apKey, aValue) {
		InitCollection();
		QCollection().Add(this);
	}
	SettingT<T>(const char* apKey, uint aValue) : Setting(apKey, aValue) {
		InitCollection();
		QCollection().Add(this);
	}
	SettingT<T>(const char* apKey, int aValue) : Setting(apKey, aValue) {
		InitCollection();
		QCollection().Add(this);
	}
	SettingT<T>(const char* apKey, char* aValue) : Setting(apKey, aValue) {
		InitCollection();
		QCollection().Add(this);
	}
	SettingT<T>(const char* apKey, SETTING_VALUE aValue)
		: Setting(apKey, aValue) {
		InitCollection();
		QCollection().Add(this);
	}
	virtual ~SettingT<T>();
	SettingT<T>& operator=(const SettingT<T>&);
	SettingT<T>& operator=(const u8);
	SettingT<T>& operator=(const s8);
	SettingT<T>& operator=(const bool);
	SettingT<T>& operator=(const float);
	SettingT<T>& operator=(const uint);
	SettingT<T>& operator=(const int);
	SettingT<T>& operator=(const char*);
	SettingT<T>& operator=(const SETTING_VALUE);
	int operator==(const char*) const;
	bool operator==(u8) const;
	bool operator==(s8) const;
	bool operator==(float) const;
	bool operator==(uint) const;
	bool operator==(int) const;
	bool operator==(bool) const;
	bool operator==(SettingT<T>&) const;
	bool operator!=(u8) const;
	bool operator!=(s8) const;
	bool operator!=(float) const;
	bool operator!=(uint) const;
	bool operator!=(int) const;
	bool operator!=(bool) const;
	bool operator!=(SettingT<T>&) const;
	uint operator&(uint) const;
	bool operator!() const;

	static T& QCollection() { return *pCollection; }

  protected:
	static void InitCollection();
	static T* pCollection;
};

template <typename T> class SettingCollection {
  public:
	SettingCollection(const SettingCollection<T>&);
	SettingCollection();
	virtual ~SettingCollection();
	bool WriteSettingsToFile(const char*);
	bool WriteSettingsToFile();
	bool ReadSettingsFromFile(const char*);
	bool WriteSettingsToHandle(void*);
	bool ReadSettingsFromHandle(void*);
	virtual void Add(T*);
	virtual void Remove(T*);
	virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>*);
	const char* SettingFile();
	bool QOk();
	virtual bool WriteSetting(T&);
	virtual bool ReadSetting(T&);
	bool Open(const char*, bool);
	virtual bool Open(bool);
	virtual bool Close();
	void SetFileHandle(void*);

  protected:
	virtual bool WriteSettings();
	virtual bool ReadSettings();
	void SetFileName(const char*);
	char pSettingFile[260]; // 0x004
	void* pHandle;			// 0x108
};

template <typename T> class SettingCollectionMap : public SettingCollection<T> {
  public:
	SettingCollectionMap(const SettingCollectionMap<T>&);
	SettingCollectionMap(unsigned int);
	virtual ~SettingCollectionMap();
	virtual void Add(T*);
	virtual void Remove(T*);
	virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>*);
	T& Get(const char*);
	bool Get(const char*, T*&);
	T* GetPtr(const char*);
	BSTCaseInsensitiveStringMap<T*>* GetSettingMap();

  protected:
	virtual bool WriteSettings();
	virtual bool ReadSettings();

	BSTCaseInsensitiveStringMap<T*> SettingsA; // 0x10c
};
