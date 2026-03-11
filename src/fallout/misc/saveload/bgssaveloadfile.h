#pragma once

class BGSSaveLoadFile {
public:
    BGSSaveLoadFile(const char *, bool, unsigned int);
    ~BGSSaveLoadFile();
    unsigned int Read(void *, unsigned int);
    unsigned int Write(const void *, unsigned int);
    bool Open();
    unsigned int GetFilePosition();
    unsigned int GetFileSize();
    void SeekSet(int);
    void SeekCurrent(int);
    const char *GetFileName();
    void SetSaveFileName(const char *);
    const char *GetSaveFileName();
    //   BSFile* QFile();
    unsigned int GetSimulatedFileSize();

    static BGSSaveLoadFile *CreateFileA(const char *, bool, unsigned int);

protected:
    char pSaveFileName[260]; // 0x000
    //   BSFile* pFile; // 0x104
    unsigned int iSimulatedFileSize; // 0x108
    unsigned int iSimulatedFilePosition; // 0x10c
};
