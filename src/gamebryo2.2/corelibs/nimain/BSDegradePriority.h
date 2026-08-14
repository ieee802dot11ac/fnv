#pragma once

#include "types.h"

enum PRIORITY_STATE {
	PS_NONE = 0x0000,
	PS_DEGRADING = 0x0001,
	PS_UPGRADING = 0x0002,
	PS_DEGRADED = 0x0003,
	PS_UPGRADED = 0x0004,
};

class BSDegradePriority {
  public:
	u8 cPriorityL; // 0x0
	u8 cPriorityH; // 0x1
	u8 cPriorityC; // 0x2
	u8 cState;	   // 0x3

	BSDegradePriority();
	void SetPriority(unsigned int, unsigned int);
	unsigned int QCurrentPriority() const;
	void SetCurrentPriority(unsigned int);
	void DecCurrent();
	void IncCurrent();
	void SetState(PRIORITY_STATE);
	PRIORITY_STATE QState();

	static void CalcPriority(unsigned int, unsigned int, unsigned int,
							 BSDegradePriority&);
};
