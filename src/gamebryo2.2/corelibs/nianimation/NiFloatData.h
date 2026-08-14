#pragma once

#include "nianimation/NiFloatKey.h"
#include "nimain/NiObject.h"
class NiFloatData : public NiObject {
  public:
	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const;
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	NiFloatData(const NiFloatData&);
	NiFloatData();
	virtual ~NiFloatData();
	unsigned int GetNumKeys() const;
	NiFloatKey* GetAnim(unsigned int&, NiAnimationKey::KeyType&,
						unsigned char&) const;
	void ReplaceAnim(NiFloatKey*, unsigned int, NiAnimationKey::KeyType);
	void SetAnim(NiFloatKey*, unsigned int, NiAnimationKey::KeyType);
	void GuaranteeKeysAtStartAndEnd(float, float);
	void GetSequenceData(float, float, NiPointer<NiFloatData>&);

	static NiObject* CreateObject();

  protected:
	uint m_uiNumKeys;				 // 0x08
	NiFloatKey* m_pkKeys;			 // 0x0c
	NiAnimationKey::KeyType m_eType; // 0x10
	u8 m_ucKeySize;					 // 0x14
};
