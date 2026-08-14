#pragma once

#include "xapilibi/synchapi.h"
#include <win_types.h>

class BSCriticalSection {
  public:
	CRITICAL_SECTION CriticalSection; // 0x00
	unsigned int ulThreadOwner;		  // 0x1c
	unsigned int ulPrevOwner;		  // 0x20
	int uiLockCount;				  // 0x24

	BSCriticalSection();
	~BSCriticalSection();
	void Enter(const char*) { EnterCriticalSection(&CriticalSection); }
	void Leave();
	void Lock(const char*);
	void Unlock();
	bool TryLock();
	void Wait();
	unsigned int QOwningThreadID() const;
	unsigned int QCurrentLockCount() const;
	void InitWithSpinCount(unsigned int);

	static void OutputTrackingInfo();
};
