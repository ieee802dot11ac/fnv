#pragma once

#include "nimain/NiAVObject.h"
#include "nimain/NiFrustum.h"
#include "nimain/NiPoint2.h"
#include "nimain/NiRect.h"

class NiRenderTargetGroup;

class NiCamera : public NiAVObject {
  public:
	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const;
	virtual NiObject* CreateClone(NiCloningProcess&);
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	NiCamera(const NiCamera&);
	NiCamera();
	virtual ~NiCamera();
	const NiPoint3& GetWorldLocation() const;
	NiPoint3 GetWorldDirection() const;
	NiPoint3 GetWorldUpVector() const;
	NiPoint3 GetWorldRightVector() const;
	const float* GetWorldToCameraMatrix() const;
	void SetViewFrustum(const NiFrustum&);
	const NiFrustum& GetViewFrustum() const;
	void SetMinNearPlaneDist(float);
	float GetMinNearPlaneDist() const;
	void SetMaxFarNearRatio(float);
	float GetMaxFarNearRatio() const;
	void AdjustAspectRatio(float, bool);
	void SetViewPort(const NiRect<float>&);
	const NiRect<float>& GetViewPort() const;
	bool FitNearAndFarToBound(const NiBound&);
	bool LookAtWorldPoint(const NiPoint3&, const NiPoint3&);
	bool WindowPointToRay(int, int, NiPoint3&, NiPoint3&,
						  const NiRenderTargetGroup*) const;
	void ViewPointToRay(float, float, NiPoint3&, NiPoint3&) const;
	void ScreenSpaceBoundBound(const NiBound&, NiPoint3&, NiPoint3&,
							   float) const;
	void ScreenSpaceBoundSize(const NiBound&, NiPoint2&, float) const;
	bool WorldPtToScreenPt(const NiPoint3&, float&, float&, float) const;
	bool WorldPtToScreenPt3(const NiPoint3&, float&, float&, float&,
							float) const;
	void SetLODAdjust(float);
	float GetLODAdjust() const;
	void WorldToCameraMatrix();

	static NiObject* CreateObject();

  protected:
	virtual void UpdateWorldData(NiUpdateData&);
	virtual void UpdateWorldBound();
	void CopyMembers(NiCamera*, NiCloningProcess&);

	float m_aafWorldToCam[4][4]; // 0x0c0
	NiFrustum m_kViewFrustum;	 // 0x100
	float m_fMinNearPlaneDist;	 // 0x11c
	float m_fMaxFarNearRatio;	 // 0x120
	NiRect<float> m_kPort;		 // 0x124
	float m_fLODAdjust;			 // 0x134
};
