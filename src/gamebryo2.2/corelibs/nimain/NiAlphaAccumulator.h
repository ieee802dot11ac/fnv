#pragma once

#include "nimain/NiBackToFrontAccumulator.h"
#include "nimain/NiGeometry.h"
#include "nimain/NiObject.h"
#include "nimain/NiVisibleArray.h"

class NiAlphaAccumulator : public NiBackToFrontAccumulator {
  public:
	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const;
	virtual NiObject* CreateClone(NiCloningProcess&);
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	NiAlphaAccumulator(const NiAlphaAccumulator&);
	NiAlphaAccumulator();
	virtual ~NiAlphaAccumulator();
	void SetObserveNoSortHint(bool);
	bool GetObserveNoSortHint() const;
	void SetSortByClosestPoint(bool);
	bool GetSortByClosestPoint() const;
	void SetInterfaceSort(bool);
	virtual void RegisterObjectArray(NiVisibleArray&);
	virtual bool RegisterObject(NiGeometry*);

	static NiObject* CreateObject();

  protected:
	void CopyMembers(NiAlphaAccumulator*, NiCloningProcess&);
	virtual void Sort();

	bool m_bObserveNoSortHint;	// 0x30
	bool m_bSortByClosestPoint; // 0x31
	bool m_bInterfaceSort;		// 0x32
};
