#pragma once

#include "macros.h"
#ifdef __cplusplus
extern "C" {
#endif

struct SETJMP_VECTOR4 {
    float floats[4];
};
typedef SETJMP_VECTOR4 jmp_buf[84];

int setjmp(jmp_buf env);
NORETURN void longjmp(jmp_buf env, int val);

#ifdef __cplusplus
}
#endif
