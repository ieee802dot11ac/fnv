#pragma once

#include "nimain/NiColor.h"
#include "nimain/NiPoint2.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiTConvertingStrideIterator.h"

// idk where these two go so they go here . sad!
struct NiBlendIndices {
	u8 Indices[4]; // 0x0

	const u8& operator[](int) const;
	u8& operator[](int);
};

struct NiBlendWeights {
	float fWeights[4]; // 0x0
	static const NiBlendWeights ZERO;

	NiBlendWeights(float, float, float, float);
	NiBlendWeights();
	const float& operator[](int) const;
	float& operator[](int);
	bool operator!=(const NiBlendWeights&);
	bool operator==(const NiBlendWeights&);
};

class NiGeometryDataIteratorNiBlendIndices
	: public NiTConvertingStrideIterator<NiBlendIndices> {
  public:
	NiGeometryDataIteratorNiBlendIndices(void*, unsigned int, int, bool);
	NiGeometryDataIteratorNiBlendIndices();
	void Get(int, NiBlendIndices&) const;
	void Set(int, const NiBlendIndices&);
};

class NiGeometryDataIteratorNiBlendWeights
	: public NiTConvertingStrideIterator<NiBlendWeights> {
  public:
	NiGeometryDataIteratorNiBlendWeights(void*, unsigned int, int, bool);
	NiGeometryDataIteratorNiBlendWeights();
	void Get(int, NiBlendWeights&) const;
	void Set(int, const NiBlendWeights&);
};

class NiGeometryDataIteratorNiColorA
	: public NiTConvertingStrideIterator<NiColorA> {
  public:
	NiGeometryDataIteratorNiColorA(void*, unsigned int, int, bool);
	NiGeometryDataIteratorNiColorA();
	void Get(int, NiColorA&) const;
	void Set(int, const NiColorA&);
};

class NiGeometryDataIteratorNiPoint2
	: public NiTConvertingStrideIterator<NiPoint2> {
  public:
	NiGeometryDataIteratorNiPoint2(void*, unsigned int, int, bool);
	NiGeometryDataIteratorNiPoint2();
	void Get(int, NiPoint2&) const;
	void Set(int, const NiPoint2&);
};

class NiGeometryDataIteratorNiPoint3
	: public NiTConvertingStrideIterator<NiPoint3> {
  public:
	NiGeometryDataIteratorNiPoint3(void*, unsigned int, int, bool);
	NiGeometryDataIteratorNiPoint3();
	void Get(NiPoint3&);
	void Get(int, NiPoint3&) const;
	void SetPtrTest(const NiPoint3*);
	void Set(const NiPoint3&);
	void Set(int, const NiPoint3&);
};
