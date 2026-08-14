#pragma once

#include "nimain/NiTArray.h"
#include "nimain/nitdefaultallocator.h"

template <typename T>
class NiTObjectArray : public NiTArray<T, NiTNewInterface<T> > {
  public:
	NiTObjectArray(const NiTObjectArray<T>&);
	NiTObjectArray(unsigned int, unsigned int);
	virtual ~NiTObjectArray();
	NiTObjectArray<T>& operator=(const NiTObjectArray<T>&);
};
