#pragma once
#ifdef __cplusplus
extern "C" {
#endif

double floor(double);
inline float floorf(float f) { return floor(f); }

// pdb-decompiler
double fabs(double _X); // 0xB17A80
double sqrt(double _X); // 0x251C20

#ifdef __cplusplus
}
#endif
