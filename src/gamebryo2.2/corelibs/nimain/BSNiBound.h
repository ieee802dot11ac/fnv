#pragma once

#include "nimain/NiBound.h"

class BSNiBound : public NiBound {
  public:
	BSNiBound(u16, u16);
	BSNiBound();
	void Set(NiBound&);
	uint QType();
	void SetType(uint);
	bool QAnyFlags(uint);
	bool QFlags(uint);
	void SetFlags(uint, bool);
	bool QDisabled();
	uint QLevel();
	void SetLevel(uint);
	bool KillIfOrphaned();
	bool UpdateIfAny(u16, const NiTransform&);
	bool UpdateIfAny(u16, BSNiBound&, const NiTransform&);
	bool UpdateIfNone(u16, const NiTransform&);
	bool UpdateIfNone(u16, BSNiBound&, const NiTransform&);
	bool UpdateIfOrphaned(const NiTransform&);
	BSNiBound& operator=(const BSNiBound&);
	const NiBound& operator=(const NiBound&);
};
