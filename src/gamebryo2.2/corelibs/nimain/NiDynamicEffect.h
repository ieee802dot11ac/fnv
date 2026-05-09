#pragma once

#include "nimain/NiAVObject.h"
#include "nimain/NiTPointerList.h"

class NiDynamicEffect : public NiAVObject {
public:
    enum EffectType {
        AMBIENT_LIGHT = 0x0000,
        POINT_LIGHT = 0x0002,
        DIR_LIGHT = 0x0003,
        SPOT_LIGHT = 0x0004,
        TEXTURE_EFFECT = 0x0005,
        MAX_TYPES = 0x0006,
        MAX_LIGHT_TYPE = 0x0004,
    };

    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    virtual void GetViewerStrings(NiTPrimitiveArray<char *> *);
    NiDynamicEffect(const NiDynamicEffect &);
    NiDynamicEffect();
    virtual ~NiDynamicEffect();
    NiDynamicEffect::EffectType GetEffectType() const;
    void SetSwitch(bool);
    bool GetSwitch() const;
    const NiTPointerList<NiNode *> &GetAffectedNodeList();
    void AttachAffectedNode(NiNode *);
    void DetachAffectedNode(NiNode *);
    void DetachAllAffectedNodes();
    const NiTPointerList<NiNode *> &GetUnaffectedNodeList();
    void AttachUnaffectedNode(NiNode *);
    void DetachUnaffectedNode(NiNode *);
    void DetachAllUnaffectedNodes();
    bool IsUnaffectedNode(NiNode *);
    int GetIndex() const;
    void IncRevisionID();
    unsigned int GetRevisionID() const;
    void SetRevisionID(unsigned int);
    void IncPushCount();
    void DecPushCount();
    int GetPushCount() const;

protected:
    void CopyMembers(NiDynamicEffect *, NiCloningProcess &);

    bool m_bOn; // 0xc0
    unsigned char m_ucEffectType; // 0xc1
    int m_iIndex; // 0xc4
    unsigned int m_uiPushCount; // 0xc8
    unsigned int m_uiRevID; // 0xcc
    NiTPointerList<NiNode *> m_kAffectedNodeList; // 0xd0
    NiTPointerList<NiNode *> m_kUnaffectedNodeList; // 0xdc

    static int ms_iNextIndex;
};
