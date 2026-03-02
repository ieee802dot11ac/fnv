#pragma once

#include "niobject.h"

class NiObjectNET;

class NiTimeController : public NiObject {
public:
    static const NiRTTI ms_RTTI;

    enum CycleType {
        LOOP = 0x0000,
        REVERSE = 0x0001,
        CLAMP = 0x0002,
        MAX_CYCLE_TYPES = 0x0003,
    };

    enum AnimType {
        APP_TIME = 0x0000,
        APP_INIT = 0x0001,
    };

    virtual const NiRTTI *GetRTTI() const;
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    // virtual void GetViewerStrings(NiTPrimitiveArray<char *>*);
    NiTimeController(const NiTimeController &);
    NiTimeController();
    virtual ~NiTimeController();
    void SetAnimType(AnimType);
    AnimType GetAnimType() const;
    void SetCycleType(CycleType);
    CycleType GetCycleType() const;
    void SetPlayBackwards(bool);
    bool GetPlayBackwards() const;
    void SetFrequency(float);
    float GetFrequency() const;
    void SetPhase(float);
    float GetPhase() const;
    void SetBeginKeyTime(float);
    float GetBeginKeyTime() const;
    void SetEndKeyTime(float);
    float GetEndKeyTime() const;
    virtual void Start(float);
    virtual void Stop();
    // virtual void Update(NiUpdateData &);
    virtual void SetTarget(NiObjectNET *);
    NiObjectNET *GetTarget() const;
    uint32_t ItemsInList() const;
    void SetNext(NiTimeController *);
    NiTimeController *GetNext() const { return m_spNext; }
    virtual bool IsTransformController() const;
    virtual bool IsVertexController() const;
    float GetLastScaledTime() const;
    bool DontDoUpdate(float);
    float GetStartTime() const;
    float GetLastTime() const;
    virtual float ComputeScaledTime(float);
    virtual void OnPreDisplay();
    void SetActive(bool);
    bool GetActive() const;
    virtual bool IsStreamable() const;
    virtual void ProcessClone(NiCloningProcess &);
    void ForceNextUpdate();
    NiTimeController &operator=(const NiTimeController &);

    static void StartAnimations(NiObjectNET *);
    static void StartAnimations(NiObjectNET *, float);
    static void StopAnimations(NiObjectNET *);
    static void OnPreDisplayIterate(NiTimeController *);
    static char *GetViewerString(const char *, NiTimeController::CycleType);
    static char *GetViewerString(const char *, NiTimeController::AnimType);

protected:
    void CopyMembers(NiTimeController *, NiCloningProcess &);
    void SetField(uint16_t, uint16_t, uint16_t);
    uint16_t GetField(uint16_t, uint16_t) const;
    void SetBit(bool, uint16_t);
    bool GetBit(uint16_t) const;
    void SetManagerControlledBit(bool);
    bool GetManagerControlledBit() const;
    void SetForceUpdate(bool);
    bool GetForceUpdate() const;
    void SetComputeScaledTime(bool);
    bool GetComputeScaledTime() const;
    virtual bool TargetIsRequiredType() const;
    uint16_t m_uFlags; // 0x08
    float m_fFrequency; // 0x0c
    float m_fPhase; // 0x10
    float m_fLoKeyTime; // 0x14
    float m_fHiKeyTime; // 0x18
    float m_fStartTime; // 0x1c
    float m_fLastTime; // 0x20
    float m_fWeightedLastTime; // 0x24
    float m_fScaledTime; // 0x28
    NiObjectNET *m_pkTarget; // 0x2c
    NiPointer<NiTimeController> m_spNext; // 0x30
};
