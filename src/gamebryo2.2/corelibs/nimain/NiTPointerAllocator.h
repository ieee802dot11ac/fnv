#pragma once

#include "nimain/NiTAbstractPoolAllocator.h"
template <typename T>
class NiTPointerAllocator : public NiTAbstractPoolAllocator<T> {
  public:
	void* Allocate();
	void Deallocate(void*);
};
