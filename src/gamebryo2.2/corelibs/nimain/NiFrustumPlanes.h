#pragma once

#include "nimain/NiCamera.h"
#include "nimain/NiPlane.h"

class NiFrustumPlanes {
  public:
	NiFrustumPlanes(const NiFrustum&, const NiTransform&);
	NiFrustumPlanes(const NiCamera&);
	NiFrustumPlanes();
	void Set(const NiFrustum&, const NiTransform&);
	void Set(const NiCamera&);
	const NiPlane& GetPlane(uint) const;
	void SetPlane(uint, const NiPlane&);
	bool IsPlaneActive(uint) const;
	bool IsAnyPlaneActive() const;
	bool AreAllPlanesActive() const;
	void EnablePlane(uint);
	void DisablePlane(uint);
	void EnableAllPlanes();
	void DisableAllPlanes();
	uint GetActivePlaneState() const;
	void SetActivePlaneState(uint);

  protected:
	NiPlane m_akCullingPlanes[6]; // 0x00
	uint m_uiActivePlanes;		  // 0x60
};
