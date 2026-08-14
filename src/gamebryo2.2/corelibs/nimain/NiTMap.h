#pragma once

template <typename T> class DFALL {
	void* Allocate();
	void Deallocate(void*);
};

template <typename Key, typename Value> class NiTMapItem {
  public:
	NiTMapItem<Key, Value>* m_pkNext; // 0x0
	Key m_key;						  // 0x4
	Value m_val;					  // 0x8
};

template <typename DFall, typename Key, typename Value>
class NiTMapBase { /* Size=0x10 */
  public:
	struct AntiBloatAllocator : public DFall {
		unsigned int m_uiCount;
	};

	unsigned int m_uiHashSize;				 // 0x4
	NiTMapItem<Key, Value>** m_ppkHashTable; // 0x8
	AntiBloatAllocator m_kAllocator;		 // 0xc

	NiTMapBase(unsigned int);
	virtual ~NiTMapBase();
	unsigned int GetCount() const;
	bool IsEmpty() const;
	void SetAt(Key, Value);
	bool RemoveAt(Key);
	void RemoveAll();
	bool GetAt(Key, Value&) const;
	void* GetFirstPos() const;
	void GetNext(void*&, Key&, Value&) const;
	virtual unsigned int KeyToHashIndex(Key) const;
	virtual bool IsKeysEqual(Key, Key) const;
	NiTMapItem<Key, Value>* GetPtrToAssoc(Key) const;
	virtual void SetValue(NiTMapItem<Key, Value>*, Key, Value);
	virtual void ClearValue(NiTMapItem<Key, Value>*);
	virtual NiTMapItem<Key, Value>* NewItem();
	virtual void DeleteItem(NiTMapItem<Key, Value>*);

  private:
	NiTMapBase(const NiTMapBase<DFall, Key, Value>&);
};

template <typename Key, typename Value>
class NiTMap : public NiTMapBase<DFALL<NiTMapItem<Key, Value> >, Key, Value> {
  public:
	NiTMap(const NiTMap<Key, Value>&);
	NiTMap(unsigned int);
	virtual ~NiTMap();
	virtual NiTMapItem<Key, Value>* NewItem();
	virtual void DeleteItem(NiTMapItem<Key, Value>*);
};
