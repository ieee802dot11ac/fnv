#pragma once

class BaseFormComponent { /* Size=0x4 */
public:
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(BaseFormComponent *);
    virtual bool CompareComponent(BaseFormComponent *);
    BaseFormComponent(const BaseFormComponent &);
    BaseFormComponent();
    BaseFormComponent &operator=(const BaseFormComponent &);
};
