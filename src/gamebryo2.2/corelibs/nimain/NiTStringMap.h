#pragma once

#include "nimain/NiTMap.h"
template <typename Map, typename Value>
class NiTStringTemplateMap : public Map {
  public:
	NiTStringTemplateMap(const NiTStringTemplateMap<Map, Value>&);
	NiTStringTemplateMap(unsigned int, bool);
	virtual ~NiTStringTemplateMap();
	const char* GetKeyPtrForKey(const char*);
	void SetAt(const char*, Value);

  protected:
	virtual unsigned int KeyToHashIndex(const char*) const;
	unsigned int HashChar(const char, unsigned int) const;
	virtual bool IsKeysEqual(const char*, const char*) const;
	virtual void SetValue(NiTMapItem<const char*, Value>*, const char*, Value);
	virtual void ClearValue(NiTMapItem<const char*, Value>*);
	bool m_bCopy;
};

template <typename T>
class NiTStringMap : public NiTStringTemplateMap<NiTMap<const char*, T>, T> {
  public:
	NiTStringMap(const NiTStringMap<T>&);
	NiTStringMap(unsigned int, bool);
	virtual ~NiTStringMap();
};
