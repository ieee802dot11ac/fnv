#include "XGameSetting.h"
#include "bsmain/Setting.h"
#include "fallout_shared/tesfile.h"
#include "nimain/NiViewerStrings.h"
#include "stdlib.h"

template <>
GameSettingCollection *SettingT<GameSettingCollection>::pCollection = nullptr;

uint GameSettingCollection::iMapSize = 401;

bool GameSettingCollection::ReadSetting(Setting &arSetting) {
    bool ret = false;
    TESFile *file = File();
    if (File() != nullptr) {
        file->NextChunk();
        if (file->GetTESChunk() == DATA_ID) {
            switch (Setting::DataType(arSetting.pKey)) {
            case Setting::ST_INT: {
                return file->GetChunkData(arSetting.Int());
            } break;
            case Setting::ST_FLOAT: {
                return file->GetChunkData(arSetting.Float());
            } break;
            case Setting::ST_STRING: {
                char *stackbuf = (char *)_alloca(file->GetChunkSize());
                ret = file->GetChunkData(stackbuf, 0);
                arSetting = stackbuf;
            } break;
            default: {
            } break;
            }
        }
    }
    return ret;
}

bool GameSettingCollection::Close() {
    pHandle = nullptr;
    return true;
}

bool GameSettingCollection::ReadSetting(TESFile *apFile, const char *apKey) {
    pHandle = apFile;
    pSettingFile[0] = 0;
    Setting *s = nullptr;
    SettingsA.GetAt(apKey, s);
    bool ret = false;
    if (!!s) {
        ret = ReadSetting(*s);
    }
    Close();
    return ret;
}

uint GameSettingCollection::GetViewerStrings(NiTPrimitiveArray<char *> *pStrings) {
    char *str = NiGetViewerString("GameSettings");
    pStrings->Add(str);

    uint total = SettingCollectionMap::GetViewerStrings(pStrings);
    str = NiGetViewerString("Total GameSettings", total);
    pStrings->Add(str);
    return total;
}
