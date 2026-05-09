#pragma once

#include "nimain/NiAccumulator.h"
#include "nimain/NiObject.h"
#include "nimain/NiVisibleArray.h"

class NiBackToFrontAccumulator : public NiAccumulator {
public:
    static const NiRTTI ms_RTTI;

    virtual const NiRTTI *GetRTTI() const;
    virtual NiObject *CreateClone(NiCloningProcess &);
    virtual void LoadBinary(NiStream &);
    virtual void LinkObject(NiStream &);
    virtual bool RegisterStreamables(NiStream &);
    virtual void SaveBinary(NiStream &);
    virtual bool IsEqual(NiObject *);
    NiBackToFrontAccumulator(const NiBackToFrontAccumulator &);
    NiBackToFrontAccumulator();
    virtual ~NiBackToFrontAccumulator();
    virtual void RegisterObjectArray(NiVisibleArray &);
    virtual void FinishAccumulating();

    static NiObject *CreateObject();

protected:
    void CopyMembers(NiBackToFrontAccumulator *, NiCloningProcess &);
    virtual void Sort();
    void SortObjectsByDepth(int, int);
    float ChoosePivot(int, int) const;

    NiTPointerList<NiGeometry *> m_kItems; // 0x0c
    NiTPointerList<NiGeometry *> *m_kItemsToSortAndRender; // 0x18
    int m_iNumItems; // 0x1c
    int m_iMaxItems; // 0x20
    NiGeometry **m_ppkItems; // 0x24
    float *m_pfDepths; // 0x28
    int m_iCurrItem; // 0x2c
};
