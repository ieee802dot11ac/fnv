#pragma once

#include "nimain/NiObject.h"
#include "nimain/NiProperty.h"
#include "nimain/NiRTTI.h"

class NiShadeProperty : public NiProperty {
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
	NiShadeProperty(const NiShadeProperty&);
	NiShadeProperty();
	void SetSmooth(bool);
	bool GetSmooth() const;
	bool IsEqualFast(const NiShadeProperty&) const;
	virtual int Type() const;
	int GetShaderPropertyType();
	virtual ~NiShadeProperty();

	static NiObject* CreateObject();
	static int GetType();
	static NiShadeProperty* GetDefault();
	static void _SDMInit();
	static void _SDMShutdown();

  protected:
	void SetField(u16, u16, u16);
	u16 GetField(u16, u16) const;
	void SetBit(bool, u16);
	bool GetBit(u16) const;
	void CopyMembers(NiShadeProperty*, NiCloningProcess&);
	u16 m_uFlags;			 // 0x18
	int iShaderPropertyType; // 0x1c
	static NiPointer<NiShadeProperty> ms_spDefault;
};
