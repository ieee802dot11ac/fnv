#pragma once

#include "nimain/NiLight.h"
#include "nimain/NiRefObject.h"
#include "nimain/NiTextureEffect.h"

class NiDynamicEffectState : public NiRefObject {
public:
    class ListItem {
    public:
        NiDynamicEffectState::ListItem *m_pNext; // 0x0
        NiDynamicEffect *m_pItem; // 0x4
    };

    NiDynamicEffectState();
    NiDynamicEffectState *Copy() const;
    virtual ~NiDynamicEffectState();
    void AddEffect(NiDynamicEffect *);
    void RemoveEffect(NiDynamicEffect *);
    void *GetLightHeadPos() const;
    NiLight *GetNextLight(void *&) const;
    void *GetProjLightHeadPos() const;
    NiTextureEffect *GetNextProjLight(void *&) const;
    void *GetProjShadowHeadPos() const;
    NiTextureEffect *GetNextProjShadow(void *&) const;
    NiTextureEffect *GetEnvironmentMap() const;
    NiTextureEffect *GetFogMap() const;
    unsigned char Equal(const NiDynamicEffectState *) const;
    bool IsMultiTexture() const;

protected:
    NiDynamicEffectState(const NiDynamicEffectState &);
    void SetMultiTexture();

    bool m_bMultiTexture; // 0x08
    NiDynamicEffectState::ListItem *m_pLightList; // 0x0c
    NiDynamicEffectState::ListItem *m_pProjLightList; // 0x10
    NiDynamicEffectState::ListItem *m_pProjShadowList; // 0x14
    NiTextureEffect *m_pEnvMap; // 0x18
    NiTextureEffect *m_pFogMap; // 0x1c

    static bool ListsEqual(
        const NiDynamicEffectState::ListItem *, const NiDynamicEffectState::ListItem *
    );
    static void ListDelete(NiDynamicEffectState::ListItem *&);
    static void
    ListCopy(const NiDynamicEffectState::ListItem *, NiDynamicEffectState::ListItem *&);
    static void ListInsertSorted(NiDynamicEffectState::ListItem *&, NiDynamicEffect *);
    static void ListRemove(NiDynamicEffectState::ListItem *&, NiDynamicEffect *);
};
