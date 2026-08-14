#include "NiPoint3.h"
#include "nisystem/NiMemoryDefines.h"
#include "nisystem/NiSystem.h"
#include <cmath>
#include <cstring>

const NiPoint3 NiPoint3::ZERO(0, 0, 0);
const NiPoint3 NiPoint3::UNIT_X(1, 0, 0);
const NiPoint3 NiPoint3::UNIT_Y(0, 1, 0);
const NiPoint3 NiPoint3::UNIT_Z(0, 0, 1);
const NiPoint3 NiPoint3::UNIT_ALL(1, 1, 1);
const NiPoint3 NiPoint3::INFINITY_POINT3(NI_INFINITY, NI_INFINITY, NI_INFINITY);

// MERGED!!! with NiColor::SaveBinary(NiStream&)
void NiPoint3::SaveBinary(NiStream& stream) {
	NiStreamSaveBinary(stream, x);
	NiStreamSaveBinary(stream, y);
	NiStreamSaveBinary(stream, z);
}

char* NiPoint3::GetViewerString(char const* pPrefix) const {
	uint len = strlen(pPrefix) + 0x40;
	char* s =
		(char*)NiMalloc(len,
						"D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2."
						"2\\CoreLibs\\NiMain\\NiPoint3.cpp",
						46);
	NiSprintf(s, len, "%s = (%g, %g, %g)", pPrefix, x, y, z);
	return s;
}

uint* NiPoint3::InitSqrtTable() {
	float f;
	uint* fuckery = reinterpret_cast<uint*>(&f);
	uint* table = (uint*)NiMalloc(
		0x100 * sizeof(uint),
		"D:\\_Fallout3\\Platforms\\Common\\Code\\Gamebryo2."
		"2\\CoreLibs\\NiMain\\NiPoint3.cpp",
		67 // nightmare nightmare nightmare nightmare nightmare nightmare
	);
	// get ready for some evil bullshit
	// tl;dr: writes raw values into the high-order mantissa bits of a 1.0f
	// instead of... using += 0.whateverf;
	for (uint i = 0; i < 128; i++) {
		*fuckery = 0x3F800000 | (i << 16);
		f = sqrt(f);
		table[i] = *fuckery & ~0xFF800000;
		*fuckery = 0x40000000 | (i << 16);
		f = sqrt(f);
		table[i + 0x80] = *fuckery & ~0xFF800000;
		// the best part? going from 1 to 256 would've incremented the 3F80
		// over to 4000 anyways. why did they do this. what the hell.
	}
	return table;
}
