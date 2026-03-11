#include "bgssaveformbuffer.h"
#include "fallout/misc/saveload/bgssavegamebuffer.h"
// #include "fallout_shared/tesobjectrefr.h"

BGSSaveFormBuffer::BGSSaveFormBuffer() { pForm = nullptr; }

void BGSSaveFormBuffer::Save(BGSSaveLoadFile *apFile) {}

void BGSSaveFormBuffer::SetHeader(
    uint aiFormID, BGSChangeFlags aiChangeFlags, ENUM_FORM_ID aeFormType, u8 acVersion
) {
    Header.FormIDIndex.SetNumericID(aiFormID);
    Header.iChangeFlags = aiChangeFlags;
    Header.FormInfo.SetFormType(aeFormType);
    Header.cVersion = acVersion;
}

uint BGSSaveFormBuffer::GetOverhead() {
    return GetSizeTypeSize(GetSizeTypeForSize(iBufferPosition)) + 9;
}

TESObjectREFR *BGSSaveFormBuffer::GetReference() {
    TESForm *form = GetForm();
    if (form != nullptr) {
        if (form->IsReference()) {
            return (TESObjectREFR *)form;
        }
    }
    return nullptr;
}

Actor *BGSSaveFormBuffer::GetActor() {
    TESObjectREFR *reference = GetReference();
    if (reference != nullptr) {
    }
    return nullptr;
}
