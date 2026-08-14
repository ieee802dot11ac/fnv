#pragma once

#include "fallout_shared/BGSDestructibleObjectForm.h"
#include "fallout_shared/BGSExplosion.h"
#include "fallout_shared/BGSPreloadable.h"
#include "fallout_shared/TESFullName.h"
#include "fallout_shared/TESSound.h"
#include "fallout_shared/enums.h"
#include "fallout_shared/tesobjectrefr.h"
#include "win_types.h"

struct BGSProjectileData {				 /* Size=0x54 */
	uint iFlags;						 // 0x00
	float fGravity;						 // 0x04
	float fSpeed;						 // 0x08
	float fRange;						 // 0x0c
	TESObjectLIGH* pLight;				 // 0x10
	TESObjectLIGH* pMuzzleFlashLight;	 // 0x14
	float fTracerChance;				 // 0x18
	float fExplosionProximity;			 // 0x1c
	float fExplosionTimer;				 // 0x20
	BGSExplosion* pExplosionType;		 // 0x24
	TESSound* pActiveSoundLoop;			 // 0x28
	float fMuzzleFlashDuration;			 // 0x2c
	float fFadeOutTime;					 // 0x30
	float fForce;						 // 0x34
	TESSound* pCountdownSound;			 // 0x38
	TESSound* pDeactivateSound;			 // 0x3c
	TESObjectWEAP* pDefaultWeaponSource; // 0x40
	float fRotationX;					 // 0x44
	float fRotationY;					 // 0x48
	float fRotationZ;					 // 0x4c
	float fBounceMultiplier;			 // 0x50

	void Initialize();
	void Endian();
};

class BGSProjectile : public TESBoundObject,
					  public TESFullName,
					  public TESModel,
					  public BGSPreloadable,
					  public BGSDestructibleObjectForm {
  public:
	enum BGSProjectileFlags {
		HITSCAN = 0x0001,
		EXPLOSION = 0x0002,
		EXPLOSION_ALT_TRIGGER = 0x0004,
		MUZZLE_FlASH = 0x0008,
		BOUNCE_ON_IMPACT = 0x0010,
		CAN_TURN_OFF = 0x0020,
		CAN_PICKUP = 0x0040,
		SUPERSONIC = 0x0080,
		PINS_LIMBS = 0x0100,
		PASS_SM_TRANSPARENT = 0x0200,
		EXPLOSION_DETONATES = 0x0400,
		HAS_ROTATION = 0x0800,
		MOTION_MISSILE = 0x00010000,
		MOTION_GRENADE = 0x00020000,
		MOTION_BEAM = 0x00040000,
		MOTION_FLAMETHROWER = 0x00080000,
		MOTION_CONTINUOUS_BEAM = 0x00100000,
		MOTIONTYPES = 0x001f0000,
	};

	BGSProjectile(const BGSProjectile&);
	BGSProjectile();
	virtual ~BGSProjectile();
	BGSProjectileData* GetData();
	virtual void InitializeData();
	virtual bool Load(TESFile*);
	virtual void Save();
	virtual void Copy(TESForm*);
	virtual bool Compare(TESForm*);
	virtual void InitItem();
	virtual void ClearData();
	virtual NiAVObject* Clone3D(TESObjectREFR*, bool);
	virtual void UnClone3D(TESObjectREFR*);
	bool GetHitScan();
	bool GetHasExplosion();
	bool GetHasExplosionAltTrigger();
	bool GetHasExplosionDetonates();
	bool GetHasMuzzleFlash();
	bool GetCanTurnOff();
	bool GetCanPickup();
	bool GetSupersonic();
	bool GetPinsLimbs();
	bool GetPassThroughSmTransp();
	float GetGravity();
	float GetSpeed();
	float GetRange();
	float GetTracerChance();
	float GetExplosionProximity();
	float GetExplosionTimer();
	TESObjectLIGH* GetLight();
	TESObjectLIGH* GetMuzzleFlashLight();
	float GetMuzzleFlashDuration();
	BGSExplosion* GetExplosion();
	TESModel& GetMuzzleFlashModel();
	BGSProjectileFlags GetMotionType();
	TESSound* GetActiveSound();
	TESSound* GetCountdownSound();
	TESSound* GetDeactivateSound();
	SOUND_LEVEL GetSoundLevel();
	float GetFadeOutTime();
	float GetForce();
	TESObjectWEAP* GetDefaultWeaponSource();
	void SetHitScan(bool);
	void SetHasExplosion(bool);
	void SetHasExplosionAltTrigger(bool);
	void SetHasExplosionDetonates(bool);
	void SetHasMuzzleFlash(bool);
	void SetCanTurnOff(bool);
	void SetCanPickup(bool);
	void SetSupersonic(bool);
	void SetPinsLimbs(bool);
	void SetPassThroughSmTransp(bool);
	void SetGravity(float);
	void SetSpeed(float);
	void SetRange(float);
	void SetTracerChance(float);
	void SetExplosionProximity(float);
	void SetExplosionTimer(float);
	void SetLight(TESObjectLIGH*);
	void SetMuzzleFlashLight(TESObjectLIGH*);
	void SetMuzzleFlashDuration(float);
	void SetExplosion(BGSExplosion*);
	void SetMotionType(BGSProjectileFlags);
	void SetActiveSound(TESSound*);
	void SetCountdownSound(TESSound*);
	void SetDeactivateSound(TESSound*);
	void SetSoundLevel(SOUND_LEVEL);
	void SetFadeOutTime(float);
	void SetForce(float);
	void SetDefaultWeaponSource(TESObjectWEAP*);
	void SetRotationX(float);
	void SetRotationY(float);
	void SetRotationZ(float);
	void SetBounceMultiplier(float);
	void SetHasRotation(bool);
	float GetRotationX();
	float GetRotationY();
	float GetRotationZ();
	float GetBounceMultiplier();
	bool GetHasRotation();
	void ClearMotionType();
	bool IsFlagSet(BGSProjectileFlags);
	void SetFlag(BGSProjectileFlags, bool);
	ENUM_FORM_ID GetProjectileRefFormType();
	virtual bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*,
						  int);
	bool DecideIsTracer();
	virtual void QueueFiles(IO_TASK_PRIORITY, QueuedFile*);
	int GetPreCloneCount(TESObjectWEAP*);
	void EnableWindowComponents(HWND*);

  private:
	BGSProjectileData Data;	   // 0x70
	TESModel MuzzleFlashModel; // 0xc4
	SOUND_LEVEL eSoundLevel;   // 0xdc
};
