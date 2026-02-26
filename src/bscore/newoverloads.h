#pragma once
#include <types.h>

void *ourMalloc(uint aSize, char const *apFileName, uint aiLine, char const *apFunction);
void ourFree(void *apPtr);
void *simpleMalloc(void *opaque, uint aiNumItems, uint aSize);
void simpleFree(void *opaque, void *apPtr);
