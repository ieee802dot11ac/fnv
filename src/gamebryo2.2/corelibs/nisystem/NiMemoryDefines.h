#pragma once

#define NiMalloc(size, file, line) _NiMalloc(size, file, line, __FUNCTION__)

void *_NiMalloc(unsigned int, char const *, int, char const *);
void _NiFree(void *);
