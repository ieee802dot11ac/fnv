#pragma once

#include "nimain/NiColor.h"
#include "nimain/NiGeometryData.h"
#include "nimain/NiPoint2.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiTriBasedGeomData.h"

class NiTriStripsData : public NiTriBasedGeomData {
  public:
	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const;
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	NiTriStripsData(const NiTriStripsData&);
	NiTriStripsData();
	NiTriStripsData(u16, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*, u16,
					NiGeometryData::DataFlags, u16, u16, u16*, u16*);
	virtual ~NiTriStripsData();
	virtual void GetTriangleIndices(u16, u16&, u16&, u16&) const;
	u16 GetStripCount() const;
	u16* GetStripLengths() const;
	u16* GetStripLists() const;
	u16 GetStripLengthSum() const;
	virtual NiTriStripsData* IsTriStripsData();
	void SetData(u16, u16*, u16*);
	void Replace(u16, u16*, u16*);
	virtual void CalculateNormals();
	virtual void GetStripData(u16&, const u16*&, const u16*&,
							  unsigned int&) const;
	virtual unsigned int GetBlockAllocationSize() const;

	static NiObject* CreateObject();

  protected:
	u16 m_usStrips;			// 0x44
	u16* m_pusStripLengths; // 0x48
	u16* m_pusStripLists;	// 0x4c
};
