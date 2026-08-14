#pragma once

#include "nimain/NiPlane.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiTransform.h"

class NiBound {
  public:
	NiPoint3 m_kCenter; // 0x0
	union {
		float m_fRadius;	// 0xc
		int m_iRadiusAsInt; // 0xc
	};

	NiBound();
	void SetCenter(float, float, float);
	void SetCenter(const NiPoint3&);
	const NiPoint3& GetCenter() const;
	void SetRadius(float);
	float GetRadius() const;
	void SetCenterAndRadius(const NiPoint3&, float);
	bool operator==(const NiBound&);
	bool operator!=(const NiBound&);
	void ComputeFromData(int, const NiPoint3*);
	void Update(const NiTransform&);
	void Update(const NiBound&, const NiTransform&);
	void ComputeMinimalBound(NiTPrimitiveArray<const NiBound*>&);
	void Merge(const NiBound*);
	int WhichSide(const NiPlane&) const;
	void LoadBinary(NiStream&);
	void SaveBinary(NiStream&);
	char* GetViewerString(const char*) const;

	static bool TestIntersect(float, const NiBound&, const NiPoint3&,
							  const NiBound&, const NiPoint3&);
	static bool FindIntersect(float, const NiBound&, const NiPoint3&,
							  const NiBound&, const NiPoint3&, float&,
							  NiPoint3&, bool, NiPoint3&, NiPoint3&);

  private:
	static float ms_fFuzzFactor;
	static float ms_fTolerance;
};
