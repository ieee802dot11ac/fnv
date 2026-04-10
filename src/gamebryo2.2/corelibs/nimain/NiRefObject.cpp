#include "nirefobject.h"

uint NiRefObject::ms_uiObjects = 0;

void NiRefObject::BETAVERSION_TEST_ClearRefCount() { m_uiRefCount = 0; }

// why...?
void NiRefObject::DeleteThis() { delete this; }
