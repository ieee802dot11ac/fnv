#pragma once

#include "fallout_shared/tesfile.h"
#include "gamebryo2.2/corelibs/nimain/niavobject.h"
#include "fallout_shared/tesform.h"

class TESSound : public TESBoundAnimObject, public TESSoundFile {
    struct SOUND_DATA {
        unsigned char iMin; // 0x00
        unsigned char iMax; // 0x01
        char iPitch; // 0x02
        unsigned char iPadding1; // 0x03
        unsigned int iFlags; // 0x04
        unsigned short iAttenuation; // 0x08
        unsigned short iTimeConstraints; // 0x0a
        unsigned short pAttenuationCurve[5]; // 0x0c
        unsigned short iReverbAttenuation; // 0x16
        unsigned int iPriority; // 0x18
        unsigned int iLoopBegin; // 0x1c
        unsigned int iLoopEnd; // 0x20

        void Endian();
    };
    static unsigned int randomNameHashes[10];
    static char randomNameHashesLastPick[10];
    static char lastSoundHash;
    static char *pPassthroughSoundNames[10];

    TESSound(const TESSound &);
    TESSound();
    virtual ~TESSound();
    virtual void Save();
    virtual bool Load(TESFile *);
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual NiAVObject *Clone3D(TESObjectREFR *);
    virtual void UnClone3D(TESObjectREFR *);
    virtual void InitializeData();
    char GetRandomPercentChance();
    const char *GetFilename();
    unsigned char GetMinDistance();
    void SetMinDistance(int);
    unsigned char GetMaxDistance();
    void SetMAXDistance(int);
    void SetFreqAdjust(char);
    char GetFreqAdjust();
    void SetStaticAttenuation(unsigned short);
    unsigned short GetStaticAttenuation();
    void SetAttenuationCurveValue(int, unsigned short);
    unsigned short GetAttenuationCurveValue(int);
    void SetReverbAttenuation(unsigned short);
    unsigned short GetReverbAttenuation();
    void SetFlag(unsigned int, bool);
    unsigned char GetStartTime();
    void SetStartTime(unsigned short);
    unsigned char GetEndTime();
    void SetEndTime(unsigned short);
    unsigned char GetPriority();
    void SetPriority(unsigned char);
    void SetPriorityFlag(unsigned int, bool);
    bool GetPriorityFlag(unsigned int);
    SOUND_DATA GetData();
    bool IsRadioSound();
    TESSound &operator=(const TESSound &);

    static char *GetPassThroughSoundName(int);
    static TESSound *GetPassThroughSound(int);
    static bool RadioSoundFilter(TESForm *, int);
    static TESSound *FindSoundByFilename(const char *);
    static float GetWeaponSoundPct();
    static float GetArmorSoundPct();
    static float GetFleshSoundPct();
    static unsigned int ConvertLoopFlag(unsigned int);
    static void GenerateDefaultObjects();
    static bool PickRandomFilename(char *);
    static bool PickSmallestFile(char *);

private:
    SOUND_DATA data; // 0x4c
    char cRandomPercentChance; // 0x70
};
