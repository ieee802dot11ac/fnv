#pragma once

#include "fallout_shared/BGSTextureSet.h"
#include "fallout_shared/TESSound.h"
#include "fallout_shared/tesfile.h"
#include "fallout_shared/tesmodel.h"

class BGSImpactData : public TESForm, public TESModel {
  public:
	enum ORIENTATION {
		ORIENT_SURFACE_NORMAL = 0x0000,
		ORIENT_PROJ_VECTOR = 0x0001,
		ORIENT_PROJ_REFLECT = 0x0002,
		ORIENT_COUNT = 0x0003,
	};

	struct OLD_IMPACT_DATA_DATA {
		float fDecalMinWidth;				// 0x00
		float fEffectDuration;				// 0x04
		float fParallaxScale;				// 0x08
		BGSImpactData::ORIENTATION eOrient; // 0x0c
		u8 cFlags;							// 0x10
		u8 cParallaxPasses;					// 0x11
		float fDecalMaxWidth;				// 0x14
		float fDepth;						// 0x18
		float fDecalMinHeight;				// 0x1c
		float fDecalMaxHeight;				// 0x20
		float fShininess;					// 0x24
		float fAngleThreshold;				// 0x28
		float fPlacementRadius;				// 0x2c
		uint iColor;						// 0x30
		SOUND_LEVEL eSoundLevel;			// 0x34

		void Endian();
	};

	struct IMPACT_DATA_DATA {
		float fEffectDuration;	 // 0x00
		ORIENTATION eOrient;	 // 0x04
		float fAngleThreshold;	 // 0x08
		float fPlacementRadius;	 // 0x0c
		SOUND_LEVEL eSoundLevel; // 0x10
		u8 cFlags;				 // 0x14

		void Endian();
	};

	BGSImpactData(const BGSImpactData&);
	BGSImpactData();
	virtual ~BGSImpactData();
	virtual void InitializeData();
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	virtual bool Load(TESFile*);
	virtual void Save();
	virtual void InitItem();
	bool GetUseTextureSetDecalData();
	void SetUseTextureSetDecalData(bool);
	void CopyDecalDataFromTextureSet();
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
	float GetDecalAngleThreshold();
	void SetDecalAngleThreshold(float);
	float GetPlacementRadius();
	void SetPlacementRadius(float);
	bool IsParallax();
	void SetParallax(bool);
	bool GetAlphaBlending();
	void SetAlphaBlending(bool);
	bool GetAlphaTesting();
	void SetAlphaTesting(bool);
	float GetDecalParallaxScale();
	void SetDecalParallaxScale(float);
	unsigned short GetDecalParallaxPasses();
	void SetDecalParallaxPasses(unsigned short);
	float GetEffectDuration();
	void SetEffectDuration(float);
	BGSImpactData::ORIENTATION GetImpactOrientation();
	void SetImpactOrientation(BGSImpactData::ORIENTATION);
	unsigned int GetDecalColor();
	void SetDecalColor(unsigned int);
	BGSTextureSet* GetDecalTextureSet();
	void SetDecalTextureSet(BGSTextureSet*);
	TESSound* GetSound1();
	void SetSound1(TESSound*);
	TESSound* GetSound2();
	void SetSound2(TESSound*);
	SOUND_LEVEL GetSoundLevel();
	void SetSoundLevel(int);
	int GetSoundLevelValue();

  protected:
	BGSImpactData::IMPACT_DATA_DATA Data; // 0x40
	BGSTextureSet* pDecalTextureSet;	  // 0x58
	TESSound* pSound1;					  // 0x5c
	TESSound* pSound2;					  // 0x60
	DecalData DData;					  // 0x64
};
