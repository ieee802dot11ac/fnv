#pragma once

#include "types.h"

template <typename T, int N> class BSSimpleArray { /* Size=0x10 */
  public:
	BSSimpleArray(uint, uint);
	BSSimpleArray(uint);
	BSSimpleArray();
	virtual ~BSSimpleArray();
	uint GetSize() const;
	void SetSize(uint, bool);
	uint GetReservedSize() const;
	void SetReservedSize(uint);
	bool IsEmpty() const;
	const T& operator[](uint) const;
	T& operator[](uint);
	const T& GetAt(int) const;
	T& GetAt(int);
	void SetAt(int, const T&);
	const T& GetFirst() const;
	T& GetFirst();
	const T& GetLast() const;
	T& GetLast();
	uint Add(const T&);
	uint AddN(const T&, uint);
	uint AddUninitialized();
	void Insert(uint, const T&);
	void InsertDefaultItems(uint, uint);
	void Remove(uint, bool);
	void RemoveRange(uint, uint, bool);
	void RemoveFast(uint, uint);
	void RemoveLast();
	void Clear(bool);
	void Swap(uint, uint);
	void Reverse();
	void QuickSort(int (*)(const void*, const void*));
	void SortedInsert(const T&, int (*)(const void*, const void*));
	void SortedInsert(const T&);
	uint SortedFind(const T&, int (*)(const void*, const void*)) const;
	bool IsInArray(const T&) const;
	bool IsInSortedArray(const T&);
	bool IsSorted(int (*)(const void*, const void*));

  protected:
	void _InitialSetup(uint, uint);
	virtual T* _Allocate(uint);
	virtual void _Deallocate(T*);
	virtual T* _Reallocate(T*, uint);

  private:
	void _ConstructItems(T*, uint);
	void _DestructItems(T*, uint);
	void _MoveItems(T*, T*, uint);
	void _ReallocateBuffer(uint, uint);
	void _DeallocateBuffer();
	bool _ShouldGrow() const;
	bool _ShouldShrink() const;
	uint _GetNewSizeForGrow() const;
	uint _GetNewSizeForShrink() const;

	T* pBuffer;			// 0x4
	uint iSize;			// 0x8
	uint iReservedSize; // 0xc

	static int QuickSortFunction(const void*, const void*);
};
