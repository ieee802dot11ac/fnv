#pragma once
#include "win_types.h"

LONG _InterlockedIncrement(LONG volatile *Addend);
LONG _InterlockedDecrement(LONG volatile *Addend);
