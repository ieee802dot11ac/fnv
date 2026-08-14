#pragma once

#include <cstddef>
#include <types.h>

template <typename T> class NiTMallocInterface {
  public:
	static T* Allocate(size_t);
	static void Deallocate(T*);
};

template <typename T> class NiTNewInterface {
  public:
	static T* Allocate(size_t);
	static void Deallocate(T*);
};
