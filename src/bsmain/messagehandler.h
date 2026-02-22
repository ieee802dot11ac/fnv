#pragma once

#include <types.h>
#include <bscore/bscoremessage.h>

enum TES_MESSAGE_TYPES {
    M_ERROR = 0,
    M_WARNING,
    M_PROGRAMFLOW,
    M_INITFLOW,
    M_DEBUGSTRING,
    M_MESSAGEBOX,
    M_MESSAGEBOX_YNA,
    M_ASSERT,
    M_MEMWARNING,
    M_CRASHTRACE,
};

class MessageHandler : public BSCoreMessage {
public:
    static MessageHandler *pHandler;
    MessageHandler(bool);
    virtual ~MessageHandler();
    static void
    Init(bool, bool, bool, bool, s32 (*const)(char const *, char const *, u32));
    static void InitSDM();
    // static void SetLoadingStream(BSStream *);
    static void SetMessageBoxCallback(s32 (*const)(char const *, char const *, u32));
    static void IncDisableWarningCount(bool);
    static void ForceNextWarningToDisplay();
    static bool QDisableWarningMessageBox();
    static void SetYesToAll(bool);
    static bool QYesToAll();
    static void SetSkipProgramFlows(bool);
    static bool QSkipProgramFlows();
    static bool QSkipInitializationFlows();
    static bool QWaitingForMessageBox();
    static void SetWarningCount(s32);
    static s32 QWarningCount();
    static MessageHandler &Handler();
    static void Close();
    static s32 Send(TES_MESSAGE_TYPES aeType, char const *apMessage, ...);
    static s32 VSend(TES_MESSAGE_TYPES, char const *, char *);
    static s32 Output(char *, char const *, ...);
    static bool ShowXUIMessageBox(char const *, char const *, u32, bool);
    static void UpdateXUIMessageBox();
    static bool IsXUIMessageBoxDisplayed();
    static bool ShouldXUIExit();
    static char const *GetWarningFileName();
    static char const *GetProgramFlowFileName();
    static char const *GetProgrammerOutputFileName();
    static char const *GetCrashTraceFileName();
    static void SetWarningFileName(char *);
    static void SetProgramFlowFileName(char *);
    static void SetProgrammerOutputFileName(char *);
    static void SetCrashTraceFileName(char *);
    static s32 MenuMessageBoxYesNoAll(char const *);
    static s32 MenuMessageBoxYesNo(char const *);
    static s32 DoMessageBox(char const *, char const *, u32);
    static void DisplayAssertQueue();
    static void SetAssertQueueing(bool);
    static void SetWarningQueueing(bool);
    static void DisplayWarningQueue();
    static void EnableWarningMessageBoxes();
    static WARNING_TYPES QWarningContext();

protected:
    enum ParamType {
        XUI_MB_TITLE = 0,
        XUI_MB_MESSAGE,
    };

    virtual void Error(char const *) override;
    virtual s32 Warning(char const *) override;
    virtual void ProgramFlow(char const *);
    virtual void InitializationFlow(char const *);
    virtual void DebugString(char const *);
    virtual void CrashTrace(char const *);
    virtual s32 MemWarning(char const *);
    static void AddToAssertQueue(char const *);
    virtual s32 Assert(char const *, u32, char const *, ...) override;
    virtual s32 Assert(char const *) override;
    static void AddToWarningQueue(char const *);
    bool bStatic; // 0x4
    static bool bDisableWarningMessageBox;
    static bool bYesToAll;
    static bool bWaitingForMessageBox;
    static s32 iDisableWarningCount;
    static bool bShowNextWarning;
    static bool bAllowYesToAll;
    static bool bSkipProgramFlows;
    static bool bSkipInitializationFlows;
    static s32 (*pMessageBoxCallback)(char const *, char const *, u32);
    static char pWarningFileName[260];
    static char pProgramFlowFileName[260];
    static char pProgrammerOutput[260];
    static char pCrashTraceFileName[260];
    // static BSStream *pLoadingStream;
    // static BSCriticalSection LoadingStreamCritical;
    virtual BSCoreMessage::MsgReturn
    Message(BSCoreMessage::MsgStyle, char const *, char const *, u32, u32) override;
    // static _XOVERLAPPED pOverlapped;
    // static _MESSAGEBOX_RESULT pResult;
    static bool bXUIExit;
    static bool bXUIMessageBoxDisplayed;
    static bool bAssertQueueOn;
    static bool bQueueAllAsserts;
    // static BSSimpleArray<BSStringT<char> const *, 1024> *qAssertQueue;
    static bool bWarningQueueOn;
    // static BSSimpleArray<BSStringT<char> const *, 1024> *qWarningQueue;
    static bool WriteFile(char const *, char const *, bool);
    static u32 NiWarning(char const *, char const *, void *);
    static void BSNiLog(s32, char const *);
};

void Error(char const *apMessage, ...);
s32 Warning(char const *apMessage, ...);
s32 Warning(WARNING_TYPES aWarningContext, char const *apMessage, ...);
void ProgramFlow(char const *apMessage, ...);
void InitializationFlow(char const *apMessage, ...);
void DebugString(char const *apMessage, ...);
