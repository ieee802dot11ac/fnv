#pragma once

#include "types.h"
class BSHash {
public:
    enum HASHPROCESS {
        HASH_FILENAME = 0x0000,
        HASH_DIRECTORY = 0x0001,
        HASH_NORMAL = 0x0002,
    };

    BSHash();
    BSHash(unsigned char, unsigned char, unsigned char, unsigned char, unsigned int);
    BSHash(const char *, HASHPROCESS);
    void GetAll(
        unsigned char &, unsigned char &, unsigned char &, unsigned char &, unsigned int &
    );
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    const unsigned long long int &Hash();
    unsigned char ExtensionIndex();
    int Compare(BSHash *);
    int Compare(BSHash &);
    int WildCardCompare(BSHash *);
    int WildCardCompare(BSHash &);
    int operator==(BSHash &);
    void MakeHashString(char *);
    void Endian();
    void Reverse();

    static void Create(const char *, const char *, BSHash &);
    static void MakeDirAndFile(const char *, BSHash &, BSHash &);

protected:
    u8 cLast; // 0x0
    u8 cLast2; // 0x1
    u8 cLength; // 0x2
    u8 cFirst; // 0x3
    uint iCRC; // 0x4
};

class BSFileEntry : public BSHash {
public:
    BSFileEntry();
    BSFileEntry(const char *, BSHash::HASHPROCESS);
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();

protected:
    void SetFileDataOffset(unsigned int);
    uint iSize; // 0x8
    uint iOffset; // 0xc
};
