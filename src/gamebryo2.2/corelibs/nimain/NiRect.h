#pragma once

#include "nimain/nistream.h"

template <typename T> class NiRect {
  public:
	T m_left;	// 0x0
	T m_right;	// 0x4
	T m_top;	// 0x8
	T m_bottom; // 0xc

	NiRect(T, T, T, T);
	void LoadBinary(NiStream&);
	void SaveBinary(NiStream&);
	char* GetViewerString(const char*) const;
};
