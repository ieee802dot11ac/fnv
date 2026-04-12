#pragma once

#include "fallout/misc/saveload/bgssaveloadfile.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/tesobjectrefr.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiQuaternion.h"

class BGSLoadGameBuffer { /* Size=0x10 */
public:
    BGSLoadGameBuffer(const BGSLoadGameBuffer &);
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    int Load(BGSSaveLoadFile *, unsigned int);
    int Load(BGSSaveLoadFile *);
    void DeleteBuffer();
    void SetBuffer(char *, unsigned int, unsigned int);
    char *GetCurrentBufferPointer();
    virtual unsigned char GetVersion();
    bool LoadFormID(unsigned int &);
    unsigned int LoadFormID();
    void LoadData(NiQuaternion *, unsigned int);
    // void LoadData(hkVector4 *, unsigned int);
    void LoadData(double *, unsigned int);
    void LoadData(NiPoint3 *, unsigned int);
    void LoadData(float *, unsigned int);
    void LoadData(uint *, unsigned int);
    void LoadData(int *, unsigned int);
    void LoadData(unsigned short *, unsigned int);
    void LoadData(short *, unsigned int);
    void LoadData(NiMatrix3 *, unsigned int);
    void LoadData(void *, unsigned int);
    char *LoadString(char *);
    int LoadVariableSizedValue();
    void AdvanceBuffer(unsigned int);
    void LoadDataEndian(void *, unsigned int, unsigned int);
    virtual TESForm *GetForm();
    virtual TESObjectREFR *GetReference();
    virtual Actor *GetActor();

protected:
    void LoadDataFromBuffer(void *, unsigned int);

    char *pBuffer; // 0x4
    unsigned int iBufferSize; // 0x8
    unsigned int iBufferPosition; // 0xc
};
