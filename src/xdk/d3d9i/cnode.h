#pragma once

#include <cstddef>

namespace D3DXShader {

    typedef enum _D3DNODE_TYPE {
        D3DNT_VOID = 0x0000,
        D3DNT_LIST = 0x0001,
        D3DNT_TREE = 0x0002,
        D3DNT_TOKEN = 0x0003,
        D3DNT_PROGRAM = 0x0004,
        D3DNT_SCOPE = 0x0005,
        D3DNT_DECL = 0x0006,
        D3DNT_USAGE = 0x0007,
        D3DNT_ARRAY = 0x0008,
        D3DNT_TYPE = 0x0009,
        D3DNT_FUNCTION = 0x000a,
        D3DNT_VARIABLE = 0x000b,
        D3DNT_STATEMENT = 0x000c,
        D3DNT_SBAPICALL = 0x000d,
        D3DNT_EXPRESSION = 0x000e,
        D3DNT_VALUE = 0x000f,
        D3DNT_BUFFER = 0x0010,
        D3DNT_STATE = 0x0011,
        D3DNT_REGISTER = 0x0012,
        D3DNT_ATTRIBUTE = 0x0013,
        D3DNT_CASECONDITION = 0x0014,
        D3DNT_CBUFFER = 0x0015,
        D3DNT_SETCALL = 0x0016,
        D3DNT_GSWITHSO = 0x0017,
        D3DNT_ASM_INSTRUCTION = 0x0018,
        D3DNT_ASM_REGISTER = 0x0019,
        D3DXNT_FORMAT = 0x001a,
        D3DXNT_UASM_INSTRUCTION = 0x001b,
        D3DXNT_UASM_REGISTER = 0x001c,
        D3DXNT_UASM_BLOCK = 0x001d,
    } D3DNODE_TYPE;

    class CNode { /* Size=0x10 */
    public:
        D3DNODE_TYPE m_Type; // 0x4
        CNode *m_pCar; // 0x8
        CNode *m_pCdr; // 0xc

        CNode(const CNode &);
        CNode(D3DNODE_TYPE);
        CNode();
        virtual int IsEqual(CNode *);
        virtual CNode *Copy();
        virtual void Print();
        // CNodeRegister *AsRegisterNode();
        // CNodeToken *AsTokenNode();
        // CNodeList *AsListNode();
        CNode &operator=(const CNode &);

        static int IsEqual(CNode *, CNode *);
        static CNode *Copy(CNode *);
        static CNode *Append(CNode *, CNode *);
        static void Print(CNode *);
        // static D3DXCore::CAlloc *SetAlloc(D3DXCore::CAlloc *);
        static unsigned char *Alloc(unsigned int, unsigned int);
        static void *operator new(size_t);
        static void operator delete(void *);
    };
}
