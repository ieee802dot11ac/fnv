#pragma once

#ifdef _MSC_VER
#define CDECL __cdecl
#define STDCALL __stdcall
#define FASTCALL __fastcall

#define SEH_TRY __try
#define SEH_EXCEPT __except
#define SEH_FINALLY __finally
#define FORCEINLINE __forceinline

#define NORETURN __declspec(noreturn)
#else
#define CDECL
#define STDCALL
#define FASTCALL

#define SEH_TRY try
#define SEH_EXCEPT catch
#define SEH_FINALLY ;
#define FORCEINLINE

#define NORETURN
#endif

#define ROTATE_LEFT(x, i) (((x) << (i)) | ((x) >> ((sizeof((x)) * 8) - (i))))
#define ROTATE_RIGHT(x, i) (((x) >> (i)) | ((x) << ((sizeof((x)) * 8) - (i))))

// clang-format off
#define DIM(x) ( sizeof(x)/sizeof(x[0]) )
// clang-format on

#define null 0

#define RELEASE(x) (delete x, x = null)
#define RELEASEARRAY(x) (delete[] (ubyte *)x, x = null)

#define ADDSTACK(x)                                                                      \
    do {                                                                                 \
        u8 _stackpad[x];                                                                 \
    } while (0);
