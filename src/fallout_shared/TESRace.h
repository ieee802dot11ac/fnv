#pragma once

#include "bsmain/Setting.h"
#include "fallout_shared/TESForm.h"
#include "fallout_shared/TESSkill.h"
#include "fallout_shared/actorvalue.h"
#include "fallout_shared/tesdescription.h"
#include "fallout_shared/tesfullname.h"
#include "fallout_shared/tesmodel.h"
#include "fallout_shared/testexture.h"
#include "nimain/nitarray.h"

struct RACE_DATA { /* Size=0x24 */
    SKILL_BONUS eSkillBonus[7]; // 0x00
    float fHeight[2]; // 0x10
    float fWeight[2]; // 0x18
    int iFlags; // 0x20

    void Endian();
};

class TESRace : public TESForm,
                public TESFullName,
                public TESDescription,
                public TESSpellList,
                public TESReactionForm { /* Size=0x4ec */
    /* 0x0000: fields for TESForm */
    /* 0x0028: fields for TESFullName */
    /* 0x0034: fields for TESDescription */
    /* 0x003c: fields for TESSpellList */
    /* 0x0050: fields for TESReactionForm */

public:
    TESRace(const TESRace &);
    TESRace();
    virtual ~TESRace();
    virtual void InitializeData();
    virtual void ClearData();
    virtual bool Load(TESFile *);
    virtual void Save();
    virtual void InitItem();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    RACE_DATA *GetData();
    SKILL_BONUS *GetSkillBonus(int);
    float GetHeight(SEX) const;
    float GetWeight(SEX) const;
    int GetRaceFlags() const;
    bool GetPlayable() const;
    bool GetBeastRace() const;
    bool GetChildRace() const;
    BGSVoiceType *GetDefaultVoiceType(SEX);
    void SetDefaultVoiceType(SEX, BGSVoiceType *);
    TESRace *GetYoungerRace() const;
    TESRace *GetOlderRace() const;
    void SetYoungerRace(TESRace *);
    void SetOlderRace(TESRace *);
    TESAttributes *GetMaleAttributes();
    TESAttributes *GetFemaleAttributes();
    unsigned char GetMaleAttribute(ActorValue::Index) const;
    unsigned char GetFemaleAttribute(ActorValue::Index) const;
    void SetMaleAttribute(ActorValue::Index, unsigned char);
    void SetFemaleAttribute(ActorValue::Index, unsigned char);
    BSSimpleList<TESHair *> *GetHairList();
    TESHair *GetRaceHair(unsigned int);
    void AddHair(TESHair *);
    void RemoveHair(TESHair *);
    void RemoveHair(unsigned int);
    void ClearHairList();
    TESHair *GetDefaultHair(SEX);
    void SetDefaultHair(SEX, TESHair *);
    char GetDefaultHairColor(SEX);
    float GetClampFaceGeoValue();
    float GetClampFaceGeoValue2();
    void SetDefaultHairColor(SEX, char);
    void SetClampFaceGeoValue(float);
    void SetClampFaceGeoValue2(float);
    BSSimpleList<TESEyes *> *GetEyeColorList();
    TESEyes *GetRaceEyeColor(unsigned int);
    void AddEyeColor(TESEyes *);
    void RemoveEyeColor(TESEyes *);
    void RemoveEyeColor(unsigned int);
    void ClearEyeColorList();
    TESEyes *GetDefaultEyeColor();
    TESModel *GetHeadPartModel(SEX, RACE_HEAD_PART);
    void SetHeadPartModel(SEX, RACE_HEAD_PART, const char *);
    TESTexture *GetHeadPartTexture(SEX, RACE_HEAD_PART);
    void SetHeadPartTexture(SEX, RACE_HEAD_PART, const char *);
    TESModel *GetBodyPartModel(SEX, RACE_BODY_PART);
    void SetBodyPartModel(SEX, RACE_BODY_PART, const char *);
    TESTexture *GetBodyPartTexture(SEX, RACE_BODY_PART);
    void SetBodyPartTexture(SEX, RACE_BODY_PART, const char *);
    const char *GetBodyPartTextureFile(SEX, RACE_BODY_PART);
    TESModel *GetBodyTextureModel(SEX);
    void SetBodyTextureModel(SEX, const char *);
    FR2MatrixVTC<float> *GetMeanFaceCoord(SEX)[2][2];
    unsigned short GetFaceCoordNum() const;
    void GetFaceGenData(TESNPC *, FaceGenNpcData &, SEX, bool);
    bool CreateHead(BSFaceGenNiNode *&, BSFaceGenNiNode *&, TESNPC *, bool, bool, SEX);
    bool GetBodyTexture(
        NiPointer<NiTexture> &, NiPointer<NiTexture> &, TESNPC *, BIPED_OBJECT, bool
    );
    bool GetBodyTextureFileName(TESNPC *, BIPED_OBJECT, char *);
    void GetBodyModTextureName(TESNPC *, char *);
    bool GetBodyModTextureFileName(TESNPC *, char *, char *);
    void KillEGTData();
    TESModel *GetPartModel(SEX, BIPED_OBJECT);
    void StoreUndo();
    void RecallUndo();

    static int GetHairColor(char);
    static const char *GetHairColorName(char);
    static const char *GetHeadPartNodeName(RACE_HEAD_PART);
    static bool GetFaceGenTexturing();
    static RACE_BODY_PART BodyPartToRaceBodyPart(BIPED_OBJECT);
    static float GetSexFaceOffset(SEX);
    static void LoadCharacterModels();
    static void ReleaseModels();

protected:
    static SettingT<GameSettingCollection> sRaceBodyTextureModelMale;
    static SettingT<GameSettingCollection> sRaceBodyTextureModelFemale;
    static SettingT<GameSettingCollection> fRaceGeneticVariation;
    static SettingT<INISettingCollection> bFaceGenTexturing;
    static const char *ppHeadPartNames[8];
    static const char *pppHeadModelFileDefaults[2][8];
    static const char *pppHeadTextureFileDefaults[2][8];
    static const char *pppBodyTextureFileDefaults[2][3];
    static const char *pppBodyModelFileDefaults[2][3];
    static const char *ppBodyTextureModelDefaults[2];

    RACE_DATA Data; // 0x060
    TESAttributes MaleAttributes; // 0x084
    TESAttributes FemaleAttributes; // 0x090
    BSSimpleList<TESHair *> HairList; // 0x09c
    TESHair *pDefaultHair[2]; // 0x0a4
    char cDefaultHairColor[2]; // 0x0ac
    float fClampFaceGeoValue; // 0x0b0
    float fClampFaceGeoValue2; // 0x0b4
    BSSimpleList<TESEyes *> EyeList; // 0x0b8
    TESModel ppHeadModelFiles[2][8]; // 0x0c0
    TESTexture ppHeadTextureFiles[2][8]; // 0x240
    TESTexture ppBodyTextureFiles[2][3]; // 0x300
    TESModel ppBodyModelFiles[2][3]; // 0x348
    BGSTextureModel pBodyTextureModels[2]; // 0x3d8
    FR2MatrixVTC<float> MeanFaceCoordFemale[2][2]; // 0x408
    FR2MatrixVTC<float> MeanFaceCoordMale[2][2]; // 0x468
    unsigned short sFaceCoordNum; // 0x4c8
    BGSVoiceType *pDefaultVoiceType[2]; // 0x4cc
    TESRace *pOldRace; // 0x4d4
    TESRace *pYoungRace; // 0x4d8
private:
    NiTPrimitiveArray<FaceGenUndo *> FaceGenUndoStates; // 0x4dc
};
