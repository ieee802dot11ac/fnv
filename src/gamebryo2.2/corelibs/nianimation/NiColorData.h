#pragma once

#include "nianimation/NiColorKey.h"
#include "nimain/NiObject.h"

class NiColorData : public NiObject {
  public:
	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const;
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	NiColorData(const NiColorData&);
	NiColorData();
	virtual ~NiColorData();
	unsigned int GetNumKeys() const;
	NiColorKey* GetAnim(unsigned int&, NiAnimationKey::KeyType&,
						unsigned char&) const;
	void ReplaceAnim(NiColorKey*, unsigned int, NiAnimationKey::KeyType);
	void SetAnim(NiColorKey*, unsigned int, NiAnimationKey::KeyType);
	void GuaranteeKeysAtStartAndEnd(float, float);
	void GetSequenceData(float, float, NiPointer<NiColorData>&);

	static NiObject* CreateObject();

  protected:
	uint m_uiNumKeys;				 // 0x08
	NiColorKey* m_pkKeys;			 // 0x0c
	NiAnimationKey::KeyType m_eType; // 0x10
	u8 m_ucKeySize;					 // 0x14
};
