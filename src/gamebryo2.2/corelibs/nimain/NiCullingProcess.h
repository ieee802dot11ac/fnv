#pragma once

#include "nimain/NiCamera.h"
#include "nimain/NiFrustumPlanes.h"
#include "nimain/NiRTTI.h"
#include "nimain/NiVisibleArray.h"
#include "vectorintrinsics.h"

class NiCullingProcess {
  public:
	static const NiRTTI ms_RTTI;

	NiCullingProcess(const NiCullingProcess&);
	NiCullingProcess(NiVisibleArray*);
	virtual ~NiCullingProcess();
	virtual void Process(const NiCamera*, NiAVObject*, NiVisibleArray*);
	void SetVisibleSet(NiVisibleArray*);
	NiVisibleArray* GetVisibleSet();
	const NiCamera* GetCamera() const;
	const NiFrustum& GetFrustum() const;
	void SetFrustum(const NiFrustum&);
	const NiFrustumPlanes& GetFrustumPlanes() const;
	void SetCamera(const NiCamera*);
	const NiFrustumPlanes* GetPlanes();
	void DisableAllPlanes();

	RTTI_BASEDEFS

  protected:
	NiCullingProcess(NiVisibleArray*, bool);
	virtual void Process(NiAVObject*);
	void DoCulling(NiAVObject*);
	void InitPlaneVectors();
	void Append(NiGeometry&);
	virtual void AppendVirtual(NiGeometry&);

	XMVECTOR p0123x;				// 0x10
	XMVECTOR p0123y;				// 0x20
	XMVECTOR p0123z;				// 0x30
	XMVECTOR p0123w;				// 0x40
	XMVECTOR p45x;					// 0x50
	XMVECTOR p45y;					// 0x60
	XMVECTOR p45z;					// 0x70
	XMVECTOR p45w;					// 0x80
	const bool m_bUseVirtualAppend; // 0x90
	NiVisibleArray* m_pkVisibleSet; // 0x94
	const NiCamera* m_pkCamera;		// 0x98
	NiFrustum m_kFrustum;			// 0x9c
	NiFrustumPlanes m_kPlanes;		// 0xb8
};
