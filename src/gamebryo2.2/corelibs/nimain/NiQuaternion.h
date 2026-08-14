#pragma once

#include "nimain/NiMatrix3.h"
#include "nimain/NiPoint3.h"

class NiQuaternion { /* Size=0x10 */
  public:
	float m_fW; // 0x0
	float m_fX; // 0x4
	float m_fY; // 0x8
	float m_fZ; // 0xc
	static const NiQuaternion IDENTITY;
	static const NiQuaternion ZERO;
	static const float ms_fEpsilon;

	NiQuaternion(float, const NiPoint3&);
	NiQuaternion(float, float, float, float);
	NiQuaternion();
	void SetW(float);
	void SetX(float);
	void SetY(float);
	void SetZ(float);
	float GetW() const;
	float GetX() const;
	float GetY() const;
	float GetZ() const;
	void SetValues(float, float, float, float);
	void GetValues(float&, float&, float&, float&) const;
	NiQuaternion operator+(const NiQuaternion&) const;
	NiQuaternion operator-() const;
	NiQuaternion operator-(const NiQuaternion&) const;
	NiQuaternion operator*(float) const;
	NiQuaternion operator*(const NiQuaternion&) const;
	NiQuaternion& operator*=(float);
	NiQuaternion& operator*=(const NiQuaternion&);
	bool operator==(const NiQuaternion&) const;
	bool operator!=(const NiQuaternion&) const;
	void Slerp(float, const NiQuaternion&, const NiQuaternion&);
	void Squad(float, const NiQuaternion&, const NiQuaternion&,
			   const NiQuaternion&, const NiQuaternion&);
	void ToAngleAxis(float&, NiPoint3&) const;
	void FromAngleAxis(float, const NiPoint3&);
	void FromAngleAxisX(float);
	void FromAngleAxisY(float);
	void FromAngleAxisZ(float);
	void FromEulerAnglesXYZ(float, float, float);
	void ToRotation(NiMatrix3&) const;
	void FromRotation(const NiMatrix3&);
	void Snap();
	void LoadBinary(NiStream&);
	void SaveBinary(NiStream&);
	char* GetViewerString(const char*) const;
	void Normalize();
	void FastNormalize();

	static float Dot(const NiQuaternion&, const NiQuaternion&);
	static NiQuaternion UnitInverse(const NiQuaternion&);
	static NiQuaternion Exp(const NiQuaternion&);
	static NiQuaternion Log(const NiQuaternion&);
	static NiQuaternion Intermediate(const NiQuaternion&, const NiQuaternion&,
									 const NiQuaternion&);
	static void LoadBinary(NiStream&, NiQuaternion*, unsigned int);
	static void SaveBinary(NiStream&, NiQuaternion*, unsigned int);

  protected:
	static float ISqrt_approx_in_neighborhood(float);
	static float Lerp(float, float, float);
	static float CounterWarp(float, float);
};
