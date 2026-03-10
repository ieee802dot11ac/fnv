#pragma once

#include "nimain/nitarray.h"
class NiGlobalStringTable {
public:
    static char *const NULL_STRING;
    static unsigned int ms_stNumStrings;
    static unsigned int ms_stNumCollisions;

    NiGlobalStringTable(const NiGlobalStringTable &);
    ~NiGlobalStringTable();
    NiGlobalStringTable &operator=(const NiGlobalStringTable &);

    static char *AddString(const char *);
    static void IncRefCount(char *&);
    static void DecRefCount(char *&);
    static const char *GetString(char *&);
    static unsigned int GetLength(char *&);
    static unsigned int GetRefCount(char *&);
    static bool ValidateString(char *&);
    static void RemoveUnusedStrings();
    static void _SDMInit();
    static void _SDMShutdown();
    static unsigned int GetBucketSize(unsigned int);
    static unsigned int GetTotalNumberOfBuckets();
    static unsigned int GetMaxBucketSize();

protected:
    static char *GetRealBufferStart(char *&);
    NiGlobalStringTable();
    char *FindString(const char *, unsigned int);
    void InsertString(char *&, unsigned int);
    void RemoveString(char *&);
    void InstanceRemoveUnusedStrings();
    unsigned int HashFunction(const char *, unsigned int);
    static NiGlobalStringTable *ms_pkTable;
    NiTPrimitiveArray<char *> m_kHashArray[513]; // 0x0
    //   NiCriticalSection m_kCriticalSection; // 0x2080
};
