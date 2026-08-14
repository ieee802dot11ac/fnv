#pragma once

#include "nimain/nistream.h"
class NiPoint2 {
  public:
	float x; // 0x0
	float y; // 0x4

  public:
	static const NiPoint2 ZERO;
	static const NiPoint2 UNIT_X;
	static const NiPoint2 UNIT_Y;

	NiPoint2(float, float);
	NiPoint2();
	const float& operator[](int) const;
	float& operator[](int);
	bool operator==(const NiPoint2&) const;
	bool operator!=(const NiPoint2&) const;
	NiPoint2 operator+(const NiPoint2&) const;
	NiPoint2 operator-() const;
	NiPoint2 operator-(const NiPoint2&) const;
	NiPoint2 operator*(float) const;
	float operator*(const NiPoint2&) const;
	NiPoint2 operator/(float) const;
	NiPoint2& operator+=(const NiPoint2&);
	NiPoint2& operator-=(const NiPoint2&);
	NiPoint2& operator*=(float);
	NiPoint2& operator/=(float);
	float Length() const;
	float SqrLength() const;
	float Dot(const NiPoint2&) const;
	float Unitize();
	void LoadBinary(NiStream&);
	void SaveBinary(NiStream&);
	char* GetViewerString(const char*) const;

	static NiPoint2 ComponentProduct(const NiPoint2&, const NiPoint2&);
	static void LoadBinary(NiStream&, NiPoint2*, unsigned int);
	static void SaveBinary(NiStream&, NiPoint2*, unsigned int);
};
