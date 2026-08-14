#pragma once

#include "types.h"

template <typename T> class NiTAbstractPoolAllocator {
  public:
	class AllocNode {
	  public:
		AllocNode* m_pkNext;	// 0x0
		void* m_pkData;			// 0x4
		unsigned int m_element; // 0x8
	};

	static void _SDMShutdown();
	static void SetBlockSize(unsigned int);
	static void EnsureFreeMem();
	static void CreateFreeMem();
	static void Lock();
	static void Unlock();

  protected:
	static AllocNode* ms_pkBlockHeader;
	static AllocNode* ms_pkFreeMem;
	static uint ms_uiBlockSize;
	//   static BSSpinLock ms_kSpinLock;
};
