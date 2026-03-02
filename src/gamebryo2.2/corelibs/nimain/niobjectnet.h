#pragma once

#include "niobject.h"
#include "niextradata.h"
#include "nifixedstring.h"
#include "nitimecontroller.h"

class NiObjectNET : public NiObject {
public:
    enum CopyType {
        COPY_NONE = 0x0000,
        COPY_EXACT = 0x0001,
        COPY_UNIQUE = 0x0002,
    };

    static const NiRTTI ms_RTTI;
    // static NiCriticalSection ExtraDataCrit;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    // virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    virtual ~NiObjectNET();
    void SetName(const NiFixedString &);
    const NiFixedString &GetName() const;
    uint16_t GetExtraDataSize() const;
    bool AddExtraData(NiExtraData *);
    bool AddExtraData(const NiFixedString &, NiExtraData *);
    NiExtraData *GetExtraData(const NiFixedString &) const;
    NiExtraData *GetExtraDataAt(uint16_t) const;
    bool RemoveExtraData(const NiFixedString &);
    bool RemoveExtraDataAt(uint16_t);
    void RemoveAllExtraData();
    bool SetExtraDataSize(uint16_t);
    void PrependController(NiTimeController *);
    void SetControllers(NiTimeController *);
    NiTimeController *GetControllers() const;
    void RemoveController(NiTimeController *);
    void RemoveAllControllers();
    bool InsertExtraData(NiExtraData *);
    void DeleteExtraData(uint16_t);
    NiTimeController *GetController(const NiRTTI *) const;
    virtual void PostLinkObject(NiStream &);
    virtual void ProcessClone(NiCloningProcess &);
    NiObjectNET(const NiObjectNET &);
    NiObjectNET &operator=(const NiObjectNET &);

    static void SetDefaultCopyType(NiObjectNET::CopyType);
    static NiObjectNET::CopyType GetDefaultCopyType();
    static void SetDefaultAppendCharacter(char);
    static char GetDefaultAppendCharacter();

protected:
    NiObjectNET();
    void CopyMembers(NiObjectNET *, NiCloningProcess &);
    NiFixedString m_kName; // 0x08
    NiPointer<NiTimeController> m_spControllers; // 0x0c
    NiExtraData **m_ppkExtra; // 0x10
    uint16_t m_usExtraDataSize; // 0x14
    uint16_t m_usMaxSize; // 0x16
    static NiObjectNET::CopyType ms_eCopyType;
    static char ms_cAppendCharacter;
};
