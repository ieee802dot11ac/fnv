#pragma once

#include "fallout_shared/tesfile.h"
#include "types.h"

struct DECAL_DATA_DATA {
	float fDecalMinWidth;  // 0x00
	float fDecalMaxWidth;  // 0x04
	float fDecalMinHeight; // 0x08
	float fDecalMaxHeight; // 0x0c
	float fDepth;		   // 0x10
	float fShininess;	   // 0x14
	float fParallaxScale;  // 0x18
	u8 cParallaxPasses;	   // 0x1c
	u8 cFlags;			   // 0x1d
	uint iColor;		   // 0x20

	void Endian();
};

class DecalData {
  public:
	DecalData();
	~DecalData();
	void Copy(DecalData*);
	bool Compare(DecalData*);
	void Save(CHUNK_ID);
	void Load(TESFile*);
	DECAL_DATA_DATA* GetData();
	float GetDecalMinWidth();
	void SetDecalMinWidth(float);
	float GetDecalMaxWidth();
	void SetDecalMaxWidth(float);
	float GetDecalMinHeight();
	void SetDecalMinHeight(float);
	float GetDecalMaxHeight();
	void SetDecalMaxHeight(float);
	float GetDecalDepth();
	void SetDecalDepth(float);
	float GetDecalShininess();
	void SetDecalShininess(float);
	bool IsParallax();
	void SetParallax(bool);
	bool GetAlphaBlending();
	void SetAlphaBlending(bool);
	bool GetAlphaTesting();
	void SetAlphaTesting(bool);
	float GetDecalParallaxScale();
	void SetDecalParallaxScale(float);
	u16 GetDecalParallaxPasses();
	void SetDecalParallaxPasses(u16);
	uint GetDecalColor();
	void SetDecalColor(uint);

	static DecalData* GetDefaultDecalData();

  protected:
	DECAL_DATA_DATA Data; // 0x0
	static DecalData DefaultDecalData;
};
