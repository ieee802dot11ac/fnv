#pragma once

#include "fallout/misc/saveload/bgssaveloadfile.h"
#include "nimain/nipoint3.h"
#include "types.h"

class TESForm;
class TESObjectREFR;
class Actor;

class BGSSaveGameBuffer {
public:
    BGSSaveGameBuffer(const BGSSaveGameBuffer &);
    BGSSaveGameBuffer();
    ~BGSSaveGameBuffer();
    void Save(BGSSaveLoadFile *, uint);
    void Save(BGSSaveLoadFile *);
    uint GetBufferPosition();
    char *GetBuffer();
    void ClearPosition();
    uint GetDataSize();
    uint GetDebugOverhead();
    //   void SaveData(NiQuaternion*, uint, uint);
    //   void SaveData(hkVector4*, uint, uint);
    void SaveData(double *, uint, uint);
    void SaveData(NiPoint3 *, uint, uint);
    void SaveData(float *, uint, uint);
    void SaveData(uint *, uint, uint);
    void SaveData(int *, uint, uint);
    void SaveData(u32 *, uint, uint);
    void SaveData(s32 *, uint, uint);
    void SaveData(u16 *, uint, uint);
    void SaveData(s16 *, uint, uint);
    //   void SaveData(NiMatrix3*, uint, uint);
    void SaveData(void *, uint, uint);
    void SaveData(void *, uint, uint, uint);
    void SaveFormID(TESForm *, uint);
    void SaveFormID(uint, uint);
    void SaveString(const char *, uint);
    uint StartVariableSizedValue();
    void SaveVariableSizedValue(uint, uint);
    void SaveVariableSizedValue(uint);
    void SaveDataEndian(void *, uint, uint, uint, uint);
    void SaveDataEndian(void *, uint, uint, uint);
    virtual TESForm *GetForm();
    virtual TESObjectREFR *GetReference();
    virtual Actor *GetActor();

protected:
    void SaveDataToBuffer(void *, uint, bool);
    void SaveDataToBuffer(void *, uint, uint, bool);
    void ExpandBuffer();
    void ShiftBuffer(uint, int);
    char *pBuffer; // 0x04
    uint iBufferSize; // 0x08
    uint iBufferPosition; // 0x0c
    uint iDebugOverhead; // 0x10
};
