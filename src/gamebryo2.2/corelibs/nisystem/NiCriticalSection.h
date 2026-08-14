#pragma once

#include "xapilibi/synchapi.h"

class NiCriticalSection { /* Size=0x80 */
  public:
	NiCriticalSection() { InitializeCriticalSection(&m_kCriticalSection); }
	~NiCriticalSection();
	void Lock();
	void Unlock();
	unsigned int GetOwningThreadID() const;
	unsigned int GetCurrentLockCount() const;

  protected:
	CRITICAL_SECTION m_kCriticalSection; // 0x00
	u32 m_ulThreadOwner;				 // 0x1c
	uint m_uiLockCount;					 // 0x20
};
