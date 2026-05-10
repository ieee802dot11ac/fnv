#pragma once

#include "bsmain/QueuedFiles.h"
#include "fallout_shared/baseformcomponent.h"
#include "fallout_shared/enums.h"

class BGSPreloadable : public BaseFormComponent {
public:
    virtual void QueueFiles(IO_TASK_PRIORITY, QueuedFile *);
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
};
