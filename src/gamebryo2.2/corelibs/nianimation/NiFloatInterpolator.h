#pragma once

#include "nianimation/NiFloatData.h"
#include "nianimation/NiFloatKey.h"
#include "nianimation/NiKeyBasedInterpolator.h"
#include "nimain/nismartpointer.h"

class NiFloatInterpolator : public NiKeyBasedInterpolator {
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
	NiFloatInterpolator(const NiFloatInterpolator&);
	NiFloatInterpolator(float);
	NiFloatInterpolator(NiFloatData*);
	virtual bool Update(float, NiObjectNET*, float&);
	virtual bool IsFloatValueSupported() const;
	NiFloatData* GetFloatData() const;
	void SetFloatData(NiFloatData*);
	void SetPoseValue(float);
	NiFloatKey* GetKeys(uint&, NiAnimationKey::KeyType&, unsigned char&) const;
	void ReplaceKeys(NiFloatKey*, uint, NiAnimationKey::KeyType);
	void SetKeys(NiFloatKey*, uint, NiAnimationKey::KeyType);
	virtual u16 GetKeyChannelCount() const;
	virtual uint GetKeyCount(u16) const;
	virtual NiAnimationKey::KeyType GetKeyType(u16) const;
	virtual NiAnimationKey::KeyContent GetKeyContent(u16) const;
	virtual NiAnimationKey* GetKeyArray(u16) const;
	virtual unsigned char GetKeyStride(u16) const;
	virtual bool GetChannelPosed(u16) const;
	virtual void Collapse();
	virtual void GuaranteeTimeRange(float, float);
	virtual NiInterpolator* GetSequenceInterpolator(float, float);
	float GetFloat();
	virtual ~NiFloatInterpolator();

	static NiObject* CreateObject();

  protected:
	void CopyMembers(NiFloatInterpolator*, NiCloningProcess&);

	float m_fFloatValue;				  // 0x0c
	NiPointer<NiFloatData> m_spFloatData; // 0x10
	uint m_uiLastIdx;					  // 0x14
};
