#pragma once

#include "bscore/memorycontexttracker.h"
#include "bsmain/Task.h"
#include "fallout_shared/enums.h"
#include "nimain/nismartpointer.h"

class QueuedChildren;
class QueuedParents;

class QueuedFile : public IOTask {
public:
    QueuedFile(const QueuedFile &);
    QueuedFile(IO_TASK_PRIORITY);
    virtual ~QueuedFile();
    virtual void Run();
    virtual void Finish();
    virtual void QueueMe();
    virtual void Requeue(IO_TASK_PRIORITY);
    virtual void Cancel(BS_TASK_STATE, void *);
    virtual void NotifyChildFinished(QueuedFile *);
    virtual void CheckFinished();
    void SetParent(QueuedFile *);
    void AddAdditionalParent(QueuedFile *);
    unsigned int GetChildCount();
    unsigned int GetChildCountFinished();
    bool GetAllChildrenFinished();

protected:
    void AddChild(QueuedFile *);

    MEM_CONTEXT eContext; // 0x18
    NiPointer<QueuedFile> spParent; // 0x1c
    QueuedChildren *pChildren; // 0x20
    QueuedParents *pAdditionalParents; // 0x24
};
