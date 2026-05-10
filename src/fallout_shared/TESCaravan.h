#pragma once

#include "bscore/memorymanager.h"
#include "fallout_shared/BGSMessageIcon.h"
#include "fallout_shared/BGSPickupPutdownSounds.h"
#include "fallout_shared/Defines.h"
#include "fallout_shared/TESModelTextureSwap.h"
#include "fallout_shared/TESScriptableForm.h"
#include "fallout_shared/TESValueForm.h"
#include "fallout_shared/TESFullName.h"
#include "fallout_shared/tesicon.h"
#include "fallout_shared/tesobject.h"
#include "fallout_shared/testexture.h"

struct CARAVANDECKDATA {
    int iDeckSize; // 0x0

    void Endian() { EndianSwapEq(iDeckSize); }
};

struct CARAVANCARDDATA {
    uint iFaceValue; // 0x0
    uint iCardSuit; // 0x4

    void Endian() {
        EndianSwapEq(iFaceValue);
        EndianSwapEq(iCardSuit);
    }
};

class TESCaravanCard : public TESBoundObject,
                       public TESFullName,
                       public TESModelTextureSwap,
                       public TESIcon,
                       public BGSMessageIcon,
                       public TESValueForm,
                       public TESScriptableForm,
                       public BGSPickupPutdownSounds {
public:
    enum CARDSUIT {
        C_HEARTS = 0x0001,
        C_SPADES = 0x0002,
        C_DIAMONDS = 0x0003,
        C_CLUBS = 0x0004,
        C_BLANK = 0x0005,
    };
    enum CARDVALUE {
        C_ACE = 0x0001,
        C_2 = 0x0002,
        C_3 = 0x0003,
        C_4 = 0x0004,
        C_5 = 0x0005,
        C_6 = 0x0006,
        C_7 = 0x0007,
        C_8 = 0x0008,
        C_9 = 0x0009,
        C_10 = 0x000a,
        NUM_VALUE_CARDS = 0x000b,
        C_JACK = 0x000c,
        C_QUEEN = 0x000d,
        C_KING = 0x000e,
        C_JOKER = 0x000f,
    };

    TESCaravanCard(const TESCaravanCard &);
    TESCaravanCard();
    virtual ~TESCaravanCard();
    virtual void InitializeData();
    virtual void InitItem();
    virtual bool Load(TESFile *);
    virtual void Save();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void ClearData();
    bool operator>(const TESCaravanCard &) const;
    virtual NiAVObject *Clone3D(TESObjectREFR *, bool);
    bool GetIsPlayable();
    void SetIsPlayable(bool);
    TESTexture *GetFaceTexture();
    TESTexture *GetBackTexture();
    CARAVANCARDDATA *GetData();
    int GetFaceValue();
    int GetCardSuit();
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(unsigned int, unsigned int);
    bool IsActive();
    void SetIsActive(bool);

    static int SortCardsFunc(const void *, const void *);

    BS_MEM_OVERLOADS

protected:
    bool bIsActive; // 0xa8
    TESTexture faceTexture; // 0xac
    TESTexture backTexture; // 0xb8
    CARAVANCARDDATA data; // 0xc4
};

class TESCaravanDeck : public TESForm, public TESFullName {
public:
    TESCaravanDeck(const TESCaravanDeck &);
    TESCaravanDeck();
    virtual ~TESCaravanDeck();
    virtual void InitializeData();
    virtual bool Load(TESFile *);
    virtual void Save();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void ClearData();
    BSSimpleList<TESCaravanCard *> *GetCaravanDeck();
    CARAVANDECKDATA *GetData();

    BS_MEM_OVERLOADS

protected:
    BSSimpleList<TESCaravanCard *> *pDeck; // 0x34
    CARAVANDECKDATA data; // 0x38
};

class TESCaravanMoney : public TESBoundObject,
                        public TESFullName,
                        public TESModelTextureSwap,
                        public TESIcon,
                        public BGSMessageIcon,
                        public TESValueForm,
                        public BGSPickupPutdownSounds {
public:
    TESCaravanMoney(const TESCaravanMoney &);
    TESCaravanMoney();
    virtual ~TESCaravanMoney();
    virtual void InitializeData();
    virtual bool Load(TESFile *);
    virtual void Save();
    virtual void Copy(TESForm *);
    virtual bool Compare(TESForm *);
    virtual void InitItem();
    virtual void ClearData();
    virtual NiAVObject *Clone3D(TESObjectREFR *, bool);
    bool GetIsPlayable();
    void SetIsPlayable(bool);
    TESModelTextureSwap *GetAnteModel(int);
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(BGSSaveFormBuffer *);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(BGSLoadFormBuffer *);
    virtual void LoadGame(unsigned int, unsigned int);

    BS_MEM_OVERLOADS

protected:
    TESModelTextureSwap anteModels[2]; // 0x9c
};
