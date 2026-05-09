#pragma once

#include "fallout_shared/actorvalue.h"
#include "fallout_shared/baseformcomponent.h"
class TESAttributes : public BaseFormComponent {
public:
    TESAttributes();
    ~TESAttributes();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    uint Save(void *);
    uint Load(void *);
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    uint GetAttributeDataSize() const;
    u8 GetAttributeValue(ActorValue::Index) const;
    void SetAttributeValue(ActorValue::Index, u8, bool);
    u8 GetStrength();
    u8 GetPerception();
    u8 GetEndurance();
    u8 GetCharisma();
    u8 GetIntelligence();
    u8 GetAgility();
    u8 GetLuck();
    void SetStrength(u8);
    void SetPerception(u8);
    void SetEndurance(u8);
    void SetCharisma(u8);
    void SetIntelligence(u8);
    void SetAgility(u8);
    void SetLuck(u8);
    u16 GetSaveSize(uint);
    void SaveGame(BGSSaveFormBuffer *);
    void SaveGame(uint);
    void LoadGame(BGSLoadFormBuffer *);
    void LoadGame(uint, uint);

protected:
    u8 cAttribute[7]; // 0x4
};
