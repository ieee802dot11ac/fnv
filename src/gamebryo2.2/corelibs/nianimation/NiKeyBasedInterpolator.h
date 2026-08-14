#pragma once

#include "nianimation/NiAnimationKey.h"
#include "nianimation/NiInterpolator.h"

class NiKeyBasedInterpolator : public NiInterpolator {
  public:
	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const { return &ms_RTTI; }
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	virtual ~NiKeyBasedInterpolator();
	virtual u16 GetKeyChannelCount() const;
	virtual uint GetKeyCount(u16) const;
	virtual NiAnimationKey::KeyType GetKeyType(u16) const;
	virtual NiAnimationKey::KeyContent GetKeyContent(u16) const;
	virtual NiAnimationKey* GetKeyArray(u16) const;
	virtual unsigned char GetKeyStride(u16) const;
	virtual bool GetChannelPosed(u16) const;
	uint GetAllocatedSize(u16) const;
	NiAnimationKey* GetKeyAt(uint, u16) const;
	void FillDerivedValues(u16);
	NiAnimationKey* GetAnim(uint&, NiAnimationKey::KeyType&, unsigned char&,
							u16) const;
	virtual void GetActiveTimeRange(float&, float&) const;
	NiKeyBasedInterpolator(const NiKeyBasedInterpolator&);
	NiKeyBasedInterpolator& operator=(const NiKeyBasedInterpolator&);

  protected:
	NiKeyBasedInterpolator();
	void CopyMembers(NiKeyBasedInterpolator*, NiCloningProcess&);
};
