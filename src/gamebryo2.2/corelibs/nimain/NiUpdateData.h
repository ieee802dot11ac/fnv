#pragma once

class NiUpdateData { /* Size=0xc */
  public:
	float fTime;				// 0x0
	bool bUpdateControllers;	// 0x4
	bool bParallelUpdate;		// 0x5
	bool bFoundParticles;		// 0x6
	bool bFoundMorphController; // 0x7
	bool bSceneGraphChange;		// 0x8
	NiUpdateData(float, bool, bool);
};
