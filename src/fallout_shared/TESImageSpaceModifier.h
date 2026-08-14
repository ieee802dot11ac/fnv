#pragma once

#include "fallout_shared/TESForm.h"
#include "fallout_shared/TESSound.h"
#include "nianimation/NiAnimationKey.h"
#include "nianimation/NiColorInterpolator.h"
#include "nianimation/NiFloatInterpolator.h"
#include "nianimation/NiLinColorKey.h"
#include "nianimation/NiLinFloatKey.h"
#include "nimain/NiPoint2.h"

class TESImageSpaceModifier : public TESForm {
  public:
	enum ImageSpaceOpParameterEnum {
		IMAGESPACEOPPARAM_HDR_FIRST = 0x0000,
		IMAGESPACEOPPARAM_HDR_EYE_ADAPT_SPEED = 0x0000,
		IMAGESPACEOPPARAM_HDR_BLUR_RADIUS = 0x0001,
		IMAGESPACEOPPARAM_HDR_SKIN_DIMMER = 0x0002,
		IMAGESPACEOPPARAM_HDR_EMISSIVE_MULT = 0x0003,
		IMAGESPACEOPPARAM_HDR_TARGET_LUM = 0x0004,
		IMAGESPACEOPPARAM_HDR_UPPER_LUM_CLAMP = 0x0005,
		IMAGESPACEOPPARAM_HDR_BRIGHT_SCALE = 0x0006,
		IMAGESPACEOPPARAM_HDR_BRIGHT_CLAMP = 0x0007,
		IMAGESPACEOPPARAM_HDR_LUM_RAMP_NO_TEX = 0x0008,
		IMAGESPACEOPPARAM_HDR_LUM_RAMP_MIN = 0x0009,
		IMAGESPACEOPPARAM_HDR_LUM_RAMP_MAX = 0x000a,
		IMAGESPACEOPPARAM_HDR_SUNLIGHT_DIMMER = 0x000b,
		IMAGESPACEOPPARAM_HDR_GRASS_DIMMER = 0x000c,
		IMAGESPACEOPPARAM_HDR_TREE_DIMMER = 0x000d,
		IMAGESPACEOPPARAM_HDR_LAST = 0x000d,
		IMAGESPACEOPPARAM_BLOOM_FIRST = 0x000e,
		IMAGESPACEOPPARAM_BLOOM_BLUR_RADIUS = 0x000e,
		IMAGESPACEOPPARAM_BLOOM_ALPHA_ADD_INTERIOR = 0x000f,
		IMAGESPACEOPPARAM_BLOOM_ALPHA_ADD_EXTERIOR = 0x0010,
		IMAGESPACEOPPARAM_BLOOM_LAST = 0x0010,
		IMAGESPACEOPPARAM_CINEMATIC_FIRST = 0x0011,
		IMAGESPACEOPPARAM_CINEMATIC_SATURATION_VALUE = 0x0011,
		IMAGESPACEOPPARAM_CINEMATIC_CONTRAST_AVG_LUM = 0x0012,
		IMAGESPACEOPPARAM_CINEMATIC_CONTRAST_VALUE = 0x0013,
		IMAGESPACEOPPARAM_CINEMATIC_BRIGHTNESS = 0x0014,
		IMAGESPACEOPPARAM_CINEMATIC_LAST = 0x0014,
		NUM_OP_PARAMS = 0x0015,
	};

	struct ImageSpaceModifierData {
		bool bAnimatable;					// 0x00
		float fDuration;					// 0x04
		uint ppuiKeySize[NUM_OP_PARAMS][2]; // 0x08
		uint uiTintColorKeySize;			// 0xb0
		uint uiBlurKeySize;					// 0xb4
		uint uiDoubleKeySize;				// 0xb8
		uint uiRadialBlurStrengthKeySize;	// 0xbc
		uint uiRadialBlurRampupKeySize;		// 0xc0
		uint uiRadialBlurStartKeySize;		// 0xc4
		bool bUseTargetForRadialBlur;		// 0xc8
		NiPoint2 RadialBlurCenter;			// 0xcc
		uint uiDepthOfFieldStrengthKeySize; // 0xd4
		uint uiDepthOfFieldDistanceKeySize; // 0xd8
		uint uiDepthOfFieldRangeKeySize;	// 0xdc
		bool bUseTargetForDepthOfField;		// 0xe0
		u8 ucDepthOfFieldMode;				// 0xe1
		uint uiRadialBlurRampDownKeySize;	// 0xe4
		uint uiRadialBlurDownStartKeySize;	// 0xe8
		uint uiFadeColorKeySize;			// 0xec
		uint uiMotionBlurStrengthKeySize;	// 0xf0

		void Endian();
	};

	enum ImageSpaceModifierOperations {
		IMAOP_MULT = 0x0000,
		IMAOP_ADD = 0x0001,
		IMAOP_COUNT = 0x0002,
	};

	TESImageSpaceModifier(const TESImageSpaceModifier&);
	TESImageSpaceModifier();
	virtual ~TESImageSpaceModifier();
	bool GetAnimatable() const;
	float GetDuration() const;
	void SetAnimatable(bool);
	void SetDuration(float);
	void Apply(float, float, NiAVObject*);
	void ApplyWeather(float, float);
	bool IsExpired(float);
	bool RemoveFloatKey(NiFloatInterpolator&);
	bool RemoveColorKey(NiColorInterpolator&);
	void MakeFloatKeyDefault(NiFloatInterpolator&, float);
	void MakeColorKeyDefault(NiColorInterpolator&);
	virtual bool Load(TESFile*);
	virtual void Save();
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	virtual void InitializeData();
	virtual void InitItem();
	virtual void ClearData();
	void FlushData();
	bool AllKeysValid();
	bool AreKeysValid(NiAnimationKey*, uint, u8);
	TESSound* GetIntroSound();
	TESSound* GetOutroSound();
	void MakeDefaultGetHit();

	static void SetEnable(bool);
	static bool GetEnable();
	static void BlendApply(float, TESImageSpaceModifier*,
						   TESImageSpaceModifier*, float, float, NiAVObject*,
						   NiAVObject*);
	static void SetCurrentTime(float);
	static float GetTickCount();
	static void AdvanceCurrentTime(float);
	static void AllowGetHit(bool);
	static TESImageSpaceModifier* GetGetHit();
	static TESImageSpaceModifier* GetConcussion();
	static TESImageSpaceModifier* GetExplosionInFace();
	static TESImageSpaceModifier* QDefault();

  protected:
	TESSound* pOutroSound;								  // 0x028
	TESSound* pIntroSound;								  // 0x02c
	TESImageSpaceModifier::ImageSpaceModifierData Data;	  // 0x030
	NiFloatInterpolator ppInterpolator[NUM_OP_PARAMS][2]; // 0x124
	NiFloatInterpolator BlurInterpolator;				  // 0x514
	NiFloatInterpolator DoubleInterpolator;				  // 0x52c
	NiColorInterpolator TintColorInterpolator;			  // 0x544
	NiColorInterpolator FadeColorInterpolator;			  // 0x568
	NiFloatInterpolator RadialBlurStrengthInterpolator;	  // 0x58c
	NiFloatInterpolator RadialBlurRampupInterpolator;	  // 0x5a4
	NiFloatInterpolator RadialBlurStartInterpolator;	  // 0x5bc
	NiFloatInterpolator RadialBlurRampDownInterpolator;	  // 0x5d4
	NiFloatInterpolator RadialBlurDownStartInterpolator;  // 0x5ec
	NiFloatInterpolator DepthOfFieldStrengthInterpolator; // 0x604
	NiFloatInterpolator DepthOfFieldDistanceInterpolator; // 0x61c
	NiFloatInterpolator DepthOfFieldRangeInterpolator;	  // 0x634
	NiFloatInterpolator MotionBlurStrengthInterpolator;	  // 0x64c
	NiLinFloatKey* pppFloatKey[NUM_OP_PARAMS][2];		  // 0x664
	NiLinFloatKey* pBlurFloatKey;						  // 0x70c
	NiLinFloatKey* pDoubleFloatKey;						  // 0x710
	NiLinColorKey* pTintColorKey;						  // 0x714
	NiLinColorKey* pFadeColorKey;						  // 0x718
	NiLinFloatKey* pRadialBlurStrengthFloatKey;			  // 0x71c
	NiLinFloatKey* pRadialBlurRampupFloatKey;			  // 0x720
	NiLinFloatKey* pRadialBlurStartFloatKey;			  // 0x724
	NiLinFloatKey* pRadialBlurRampDownFloatKey;			  // 0x728
	NiLinFloatKey* pRadialBlurDownStartFloatKey;		  // 0x72c
	NiLinFloatKey* pDepthOfFieldStrengthFloatKey;		  // 0x730
	NiLinFloatKey* pDepthOfFieldDistanceFloatKey;		  // 0x734
	NiLinFloatKey* pDepthOfFieldRangeFloatKey;			  // 0x738
	NiLinFloatKey* pMotionBlurStrengthFloatKey;			  // 0x73c
	BSStringT<char> strName;							  // 0x740
	static float fCurrentTime;
	static const int NUM_START_KEYS;
	static float fDefaultKeyTimes[2];
	static float fOpDefault[2];
	static TESImageSpaceModifier* pGetHit;
	static TESImageSpaceModifier* pConcussion;
	static TESImageSpaceModifier* pExplosionInFace;
	static TESImageSpaceModifier sDefault;
	static bool bEnable;
	static bool bAllowGetHit;
};
