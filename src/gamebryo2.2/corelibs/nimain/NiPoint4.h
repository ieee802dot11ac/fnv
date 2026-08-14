#pragma once

#include "nimain/NiPoint3.h"
#include "vectorintrinsics.h"

class NiPoint4 { /* Size=0x10 */
  public:
	union {
		XMVECTOR m_vfPt;
		float m_pt[4];
	};
	static const NiPoint4 ZERO;

	NiPoint4(XMVECTOR);
	NiPoint4(const NiPoint3&, float);
	NiPoint4(float, float, float, float);
	NiPoint4();
	bool operator==(const NiPoint4&) const;
	void MakeZero();
	void Set(const NiPoint3&, float);
	void Set(float, float, float, float);
	void SetVector(float, float, float);
	void SetVector(const NiPoint3&);
	void SetX(float);
	void SetY(float);
	void SetZ(float);
	void SetW(float);
	float X() const;
	float Y() const;
	float Z() const;
	float W() const;
	NiPoint4 operator+(const NiPoint4&) const;
	NiPoint4 operator-(const NiPoint4&) const;
	NiPoint4 operator*=(float);
	NiPoint4 operator-=(NiPoint4&);
	NiPoint4 operator*(float) const;

	static void UnitizeVectors(NiPoint4*, unsigned int, NiPoint3*);
};
