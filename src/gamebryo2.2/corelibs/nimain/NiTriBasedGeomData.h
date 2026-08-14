#pragma once

#include "nimain/NiGeometryData.h"

class NiTriBasedGeomData : public NiGeometryData {
  public:
	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const;
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	virtual ~NiTriBasedGeomData();
	unsigned short GetTriangleCount() const;
	void SetTriangleCount(unsigned short);
	virtual void SetActiveTriangleCount(unsigned short);
	virtual unsigned short GetActiveTriangleCount() const;
	virtual void GetTriangleIndices(unsigned short, unsigned short&,
									unsigned short&, unsigned short&) const;
	virtual void GetStripData(unsigned short&, const unsigned short*&,
							  const unsigned short*&, unsigned int&) const;
	NiTriBasedGeomData(const NiTriBasedGeomData&);

  protected:
	NiTriBasedGeomData();
	NiTriBasedGeomData(unsigned short, NiPoint3*, NiPoint3*, NiColorA*,
					   NiPoint2*, unsigned short, NiGeometryData::DataFlags,
					   unsigned short);

	u16 m_usTriangles;
};
