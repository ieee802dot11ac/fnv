#pragma once

#include <types.h>

class NiBinaryStream {
public:
    NiBinaryStream(const NiBinaryStream &);
    NiBinaryStream();
    virtual ~NiBinaryStream();
    virtual operator bool() const;
    virtual void Seek(int32_t);
    virtual uint32_t GetPosition() const;
    uint32_t BinaryRead(void *, uint32_t, uint32_t *, uint32_t);
    uint32_t BinaryWrite(const void *, uint32_t, uint32_t *, uint32_t);
    uint32_t Read(void *, uint32_t);
    uint32_t Write(const void *, uint32_t);
    uint32_t GetLine(char *, uint32_t);
    uint32_t PutS(const char *);
    virtual void SetEndianSwap(bool);
    void AddAbsoluteCurrentPos(const uint32_t);
    NiBinaryStream &operator=(const NiBinaryStream &);

    static bool GetEndianMatchHint();
    static void SetEndianMatchHint(bool);

protected:
    static void DoByteSwap(void *, uint32_t, uint32_t *, uint32_t);

    uint32_t m_uiAbsoluteCurrentPos; // 0x4
    uint32_t (*m_pfnRead)(NiBinaryStream *, void *, uint32_t, uint32_t *, uint32_t); // 0x8
    uint32_t (*m_pfnWrite)(
        NiBinaryStream *, const void *, uint32_t, uint32_t *, uint32_t
    ); // 0xc
    static bool ms_bEndianMatchHint;
};
