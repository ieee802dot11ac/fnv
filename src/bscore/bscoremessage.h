#pragma once

#include <types.h>

enum WARNING_TYPES {
    WARN_DEFAULT = 0,
    WARN_COMBAT,
    WARN_ANIMATION,
    WARN_AI,
    WARN_SCRIPTS,
    WARN_SAVELOAD,
    WARN_DIALOGUE,
    WARN_QUESTS,
    WARN_PACKAGES,
    WARN_EDITOR,
    WARN_MODELS,
    WARN_TEXTURES,
    WARN_PLUGINS,
    WARN_MASTERFILE,
    WARN_FORMS,
    WARN_MAGIC,
    WARN_SHADERS,
    WARN_PATHFINDING,
    WARN_MENUS,
    WARN_AUDIO,
    WARN_CELLS,
    WARN_HAVOK,
    WARN_WATER,
    WARN_INGAME_MESSAGE,
    MAX_WARNING_TYPES,
};

class BSCoreMessage {
public:
    virtual ~BSCoreMessage();
    enum MsgReturn {
        MR_NONE = 0,
        MR_ACCEPT,
        MR_REJECT,
        MR_CANCEL,
    };
    enum MsgStyle {
        MS_ASSERT = 0,
        MS_WARNING,
        MS_PROGFLOW,
        MS_INITFLOW,
        MS_DEBUGSTRING,
        MS_OK,
        MS_OKCANCEL,
        MS_YESNO,
        MS_YESNOCANCEL,
        MS_RETRYCANCEL,
        MS_NOYES,
    };
    void StatusOn(char const *, char const *, float, u32, u32);
    void StatusOff();
    static bool QInitialized();
    static BSCoreMessage &QInstance() { return *pHandler; }
    static void SetHandler(BSCoreMessage *);
    virtual void Error(char const *);
    virtual s32 Warning(char const *);
    virtual s32 Assert(char const *, u32, char const *, ...);
    virtual s32 Assert(char const *);
    virtual MsgReturn Message(MsgStyle, char const *, char const *, u32, u32);
    static void SetWarningDisabled(s32, bool);
    static bool IsWarningDisabled(s32);
    bool CheckWarningContexts(WARNING_TYPES);
    void DisableContextMessages(WARNING_TYPES);
    static void SetWarningContext(WARNING_TYPES);

protected:
    BSCoreMessage(BSCoreMessage const &);
    BSCoreMessage();
    BSCoreMessage const &operator=(BSCoreMessage const &);
    s32 DoMessageBox(char const *, char const *, u32);
    static BSCoreMessage *pHandler;
    static s32 iWarningCount;
    static bool bWarningsDisabled[24];
    static char const *WarningContextStrings[24];
    static WARNING_TYPES sCurrentWarningContext;
};

#define BS_ASSERT(cond, file, line)                                                      \
    ((cond) || (BSCoreMessage::QInstance().Assert(file, line, __FUNCTION__)))

#define BS_ASSERT_NOFUNC(cond, file, line)                                               \
    ((cond) || (BSCoreMessage::QInstance().Assert(file, line, nullptr)))
