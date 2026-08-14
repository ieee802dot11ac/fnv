#pragma once

#include "nisystem/nibinarystream.h"
#include "win_types.h"
#include "xapilibi/minwinbase.h"
#include <cstdio>

class NiFile : public NiBinaryStream {
  public:
	enum FileMethod {
		FILE_USE_POINTER = 0x0000,
		FILE_USE_HANDLE = 0x0001,
		FILE_USE_MASK = 0x000f,
		FILE_USE_DOUBLEBUFFER = 0x0080,
	};
	enum OpenMode {
		READ_ONLY = 0x0000,
		WRITE_ONLY = 0x0001,
		APPEND_ONLY = 0x0002,
	};
	class OverlappedContext { /* Size=0x20 */
	  public:
		uint m_uiFilePointer;	  // 0x0
		uint m_uiBytesExpected;	  // 0x4
		bool m_bIOPending;		  // 0x8
		OVERLAPPED m_kOverlapped; // 0xc
	};

	static const int ms_iSeekSet;
	static const int ms_iSeekCur;
	static const int ms_iSeekEnd;
	static bool bsUseDiskError;

	NiFile(const NiFile&);
	NiFile(const char*, OpenMode, unsigned int);
	virtual ~NiFile();
	virtual operator bool() const;
	virtual void Seek(int, int);
	virtual void Seek(int);
	bool GetIsEndOfBuffer();
	// virtual _XCONTENT_DATA *GetDevice();
	virtual char* FileName();
	virtual unsigned int GetFileSize() const;
	virtual void SetEndianSwap(bool);
	bool GetIsDDX();
	void SetIsDDX(bool);
	char* GetBuffer();
	unsigned int QPos();
	unsigned int QBufferAllocSize();
	unsigned int QBufferReadSize();
	void SetPos(unsigned int);
	void SetBufferReadSize(unsigned int);
	unsigned int GetCurrentFilePos();
	void SetCurrentFilePos(unsigned int);
	unsigned int DiskRead(void*, unsigned int);
	unsigned int GetActualFilePosition();
	static NiFile* GetFile(const char*, OpenMode, unsigned int);
	static void SetFileCreateFunc(NiFile* (*)(const char*, OpenMode,
											  unsigned int));
	static bool Access(const char*, OpenMode);
	static void SetFileAccessFunc(bool (*)(const char*, OpenMode));
	static bool CreateDirectoryA(const char*);
	static bool DirectoryExists(const char*);
	static void SetCreateDirectoryFunc(bool (*)(const char*));
	static void SetDirectoryExistsFunc(bool (*)(const char*));
	static bool CreateDirectoryRecursive(const char*);
	static void SetFileReadErrorFunc(void (*)());
	static void InvokeReadErrorFunc(NiFile*);
	static void SetFileMethod(unsigned int);
	static unsigned int GetFileMethod();

  protected:
	NiFile();

	static NiFile* DefaultFileCreateFunc(const char*, OpenMode, unsigned int);
	static bool DefaultFileAccessFunc(const char*, OpenMode);
	static bool DefaultCreateDirectoryFunc(const char*);
	static bool DefaultDirectoryExistsFunc(const char*);

	bool Flush();
	unsigned int DiskWrite(const void*, unsigned int);
	void StartDiskRead();
	bool CompleteDiskRead();
	unsigned int FileRead(void*, unsigned int);
	unsigned int FileWrite(const void*, unsigned int);

	static unsigned int ReadNoSwap(NiBinaryStream*, void*, unsigned int,
								   unsigned int*, unsigned int);
	static unsigned int WriteNoSwap(NiBinaryStream*, const void*, unsigned int,
									unsigned int*, unsigned int);
	static unsigned int ReadAndSwap(NiBinaryStream*, void*, unsigned int,
									unsigned int*, unsigned int);
	static unsigned int WriteAndSwap(NiBinaryStream*, const void*, unsigned int,
									 unsigned int*, unsigned int);

	static NiFile* (*ms_pfnFileCreateFunc)(const char*, OpenMode, unsigned int);
	static bool (*ms_pfnFileAccessFunc)(const char*, OpenMode);
	static bool (*ms_pfnCreateDirFunc)(const char*);
	static bool (*ms_pfnDirExistsFunc)(const char*);
	static unsigned int ms_uiFileMethodFlags;
	static unsigned int ms_dwMoveMethods[3][2];

	unsigned int m_uiBufferAllocSize; // 0x10
	unsigned int m_uiBufferReadSize;  // 0x14
	unsigned int m_uiPos;			  // 0x18
	unsigned int m_uiCurrentFilePos;  // 0x1c
	char* m_pBuffer;				  // 0x20
	FileMethod m_eFileMethod;		  // 0x24
	bool m_bUseDoubleBuffer;		  // 0x28
	FILE* m_pFile;					  // 0x2c
	HANDLE m_hFile;					  // 0x30
	unsigned int m_uiStreamBuffer;	  // 0x34
	unsigned int m_uiReadBuffer;	  // 0x38
	unsigned char* m_apBuffers[2];	  // 0x3c
	unsigned int m_uiDiskReads;		  // 0x44
	OverlappedContext m_kOLContext;	  // 0x48
	bool bIsDDX;					  // 0x68
	OpenMode m_eMode;				  // 0x6c
	bool m_bGood;					  // 0x70
};
