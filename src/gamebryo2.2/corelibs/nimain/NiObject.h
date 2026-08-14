#pragma once

#include "NiObjectGroup.h"
#include "NiRTTI.h"
#include "NiRefObject.h"
#include "nimain/BSNiBound.h"
#include "nismartpointer.h"
#include "nitarray.h"

class NiStream;
class NiCloningProcess;
class NiNode;

class NiObject : public NiRefObject {
  public:
	static const NiRTTI ms_RTTI;

	static NiObject* DynamicCast(const NiRTTI* __restrict, const NiObject*);
	virtual NiObject* CreateClone(NiCloningProcess&);
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	static NiObject* CreateObject();
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	virtual void AddViewerStrings(NiTPrimitiveArray<char*>*);
	virtual ~NiObject();
	NiObject* Clone(NiCloningProcess&);
	NiObject* Clone();
	NiObject* CreateSharedClone(NiCloningProcess&);
	virtual void ProcessClone(NiCloningProcess&);
	void CreateDeepCopy(NiPointer<NiObject>&);
	virtual void PostLinkObject(NiStream&);
	virtual bool StreamCanSkip();
	virtual const NiRTTI* GetStreamableRTTI() const;
	virtual void SetBound(BSNiBound*);
	virtual uint GetBlockAllocationSize() const;
	virtual NiObjectGroup* GetGroup() const;
	virtual void SetGroup(NiObjectGroup*);

	RTTI_BASEDEFS

  protected:
	NiObject();
	void CopyMembers(NiObject*, NiCloningProcess&);

  private:
	NiObject(const NiObject&);
	NiObject& operator=(const NiObject&);
};

#define VIEWER_STRING_ME(x) char* s_##x = NiGetViewerString(#x, x)
