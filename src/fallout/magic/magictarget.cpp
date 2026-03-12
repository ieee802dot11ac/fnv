#include "magictarget.h"
#include "fallout_shared/magic/spellitem.h"
#include "fallout/magic/activeeffect.h"

void MagicTarget::Dispel() {
    for (BSSimpleList<ActiveEffect *> *fx = GetActiveEffectList(); fx != nullptr;) {
        decltype(fx) next = fx->GetNext();
        ActiveEffect *obj = fx->GetItem();
        if (fx->IsEmpty())
            break;
        fx = next;
        if (fx->GetItem())
            obj->Dispel(true);
    }
}

MagicTarget::MagicTarget() {
    bShowTargetStats = false;
    bUpdating = false;
}

MagicTarget::~MagicTarget() {
    for (BSSimpleList<SpellDispelData *> *p = &PostUpdateDispelList; p != nullptr;
         p = p->GetNext()) {
        SpellDispelData *obj = p->GetItem();
        if (p->IsEmpty())
            break;
        if (p->GetItem() != nullptr)
            delete obj;
    }
    PostUpdateDispelList.RemoveAll();
}
