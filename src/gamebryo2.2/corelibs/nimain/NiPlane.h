#pragma once

#include "nimain/NiPoint3.h"
class NiPlane {
  public:
	NiPoint3 m_kNormal; // 0x0
	float m_fConstant;	// 0xc

	NiPlane(const NiPoint3&, const NiPoint3&, const NiPoint3&);
	NiPlane(const NiPoint3&, const NiPoint3&);
	NiPlane(const NiPoint3&, float);
	NiPlane();
	bool operator==(const NiPlane&);
	bool operator!=(const NiPlane&);
	NiPlane operator-() const;
	void SetNormal(const NiPoint3&);
	const NiPoint3& GetNormal() const;
	void SetConstant(float);
	float GetConstant() const;
	float Distance(const NiPoint3&) const;
	int WhichSide(const NiPoint3&) const;
	void LoadBinary(NiStream&);
	void SaveBinary(NiStream&);
	char* GetViewerString(const char*) const;
};
