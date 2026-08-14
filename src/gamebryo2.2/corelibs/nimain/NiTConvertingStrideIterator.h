#pragma once

template <typename T> class NiTConvertingStrideIterator {
  public:
	NiTConvertingStrideIterator<T>(void*, unsigned int, int, bool);
	NiTConvertingStrideIterator<T>();
	bool operator==(const NiTConvertingStrideIterator<T>&) const;
	bool operator!=(const NiTConvertingStrideIterator<T>&) const;
	int operator-(const NiTConvertingStrideIterator<T>&) const;
	bool operator<(const NiTConvertingStrideIterator<T>&) const;
	int DistanceTo(const NiTConvertingStrideIterator<T>) const;
	void Advance(int);
	void Next();
	void Previous();
	bool GetCompressed();
	void* GetCurrentPosition();
	int GetStride() const;
	const int& GetStride();
	void SetData(void*, unsigned int, int, bool);

  protected:
	void CheckArrayBounds_debug(int) const;

	void* m_pvCurrentPosition; // 0x0
	int m_iStride;			   // 0x4
	bool m_bCompressed;		   // 0x8
};
