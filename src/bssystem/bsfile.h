#pragma once

#include "bscore/bsstring.h"
#include "nisystem/NiFile.h"
#include "types.h"
#include "xapilibi/minwinbase.h"
#include <cstdio>
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

class BSFile : public NiFile {
public:
    static unsigned int iCount;

    BSFile(const BSFile &);
    //   public: BSFile(const char*, NiFile::OpenMode, unsigned int, bool,
    //   _XCONTENT_DATA*);
    virtual ~BSFile();
    FILE *File();
    void *Handle();
    virtual char *FileName();
    SYSTEMTIME GetLastSaveTime();
    void Close();
    bool ChangeBufferSize(unsigned int);
    bool AddAuxBuffer(unsigned int, unsigned int);
    void RemoveAuxBuffer();
    void CopyAuxBufferInfo(BSFile *);
    void ClearAuxBufferInfo();
    //   public: virtual _XCONTENT_DATA* GetDevice();
    //   public: void SetDevice(_XCONTENT_DATA);
    //   public: _XCONTENT_DATA CopyDevice();
    void RemoveDevice();
    virtual bool Open(bool, bool);
    virtual bool OpenByFilePointer(FILE *);
    virtual unsigned int GetSize();
    virtual unsigned int Read(BSStringT<char> &, unsigned int);
    virtual unsigned int Read(BSStringT<wchar_t> &, unsigned int);
    virtual unsigned int GetLine(char *, unsigned int, wchar_t);
    virtual unsigned int Write(const BSStringT<char> &, bool);
    virtual unsigned int Write(const BSStringT<wchar_t> &, bool);
    virtual bool Exist();
    virtual void Seek(int, int);
    virtual unsigned int GetFileSize() const;
    bool Flush();
    virtual unsigned int ReadF(void *, unsigned int);
    virtual unsigned int WriteF(const void *, unsigned int);
    virtual void SetEndianSwap(bool);
    bool FileIsGood();
    unsigned int Tell();
    unsigned int QTrueFilePos();
    void SetTrueFilePos(unsigned int);
    char *Buffer();
    unsigned int BufferSize();
    unsigned int BufferReadSize();
    unsigned int ReadPos();
    void SetArraySize(unsigned int);
    int Result();
    unsigned int FileSize();
    void SetFileSize(unsigned int);
    void CalculateFileSize();
    BSFile &operator<<(unsigned int *);
    BSFile &operator<<(int *);
    BSFile &operator<<(unsigned short *);
    BSFile &operator<<(short *);
    BSFile &operator<<(unsigned char *);
    BSFile &operator<<(char *);
    //   public: BSFile& operator<<(const IOSIZE&);
    BSFile &operator<<(const BSStringT<char> &);
    BSFile &operator<<(const BSStringT<wchar_t> &);
    //   public: BSFile& operator<<(const std::string&);
    BSFile &operator<<(const unsigned char *);
    BSFile &operator<<(const char *);
    BSFile &operator<<(const double &);
    BSFile &operator<<(const float &);
    BSFile &operator<<(const unsigned int &);
    BSFile &operator<<(const int &);
    BSFile &operator<<(const unsigned short &);
    BSFile &operator<<(const short &);
    BSFile &operator<<(const unsigned char &);
    BSFile &operator<<(const char &);
    BSFile &operator>>(unsigned int *);
    BSFile &operator>>(int *);
    BSFile &operator>>(unsigned short *);
    BSFile &operator>>(short *);
    BSFile &operator>>(unsigned char *);
    BSFile &operator>>(char *);
    // BSFile &operator>>(const IOSIZE &);
    BSFile &operator>>(BSStringT<char> &);
    BSFile &operator>>(BSStringT<wchar_t> &);
    BSFile &operator>>(double &);
    BSFile &operator>>(float &);
    BSFile &operator>>(unsigned int &);
    BSFile &operator>>(int &);
    BSFile &operator>>(unsigned short &);
    BSFile &operator>>(short &);
    BSFile &operator>>(unsigned char &);
    BSFile &operator>>(char &);

    static BSFile *GetFile(const char *, NiFile::OpenMode, unsigned int);
    static unsigned int
    RdNoSwap(NiBinaryStream *, void *, unsigned int, unsigned int *, unsigned int);
    static unsigned int
    WrNoSwap(NiBinaryStream *, const void *, unsigned int, unsigned int *, unsigned int);
    static unsigned int
    RdSwap(NiBinaryStream *, void *, unsigned int, unsigned int *, unsigned int);
    static unsigned int
    WrSwap(NiBinaryStream *, const void *, unsigned int, unsigned int *, unsigned int);

    bool m_bUseNoBuffering; // 0x074
    bool bUseAuxBuffer; // 0x075
    char *m_pAuxBuffer; // 0x078
    int iAuxTrueFilePos; // 0x07c
    unsigned int iAuxBufferMinIndex; // 0x080
    unsigned int iAuxBufferMaxIndex; // 0x084
protected:
    char pFileName[260]; // 0x088
    int iResult; // 0x18c
    unsigned int iIOSize; // 0x190
    unsigned int iTrueFilePos; // 0x194
    unsigned int iFileSize; // 0x198
    // _XCONTENT_DATA *m_pDevice; // 0x19c

    BSFile();
    bool FilePointerIsValid();
    void InvalidateFilePointer();
    void CheckIsGood();
};
