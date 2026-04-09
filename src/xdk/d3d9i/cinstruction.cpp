#include "d3d9i/cinstruction.h"
#include "types.h"
#include "win_types.h"

namespace D3DXShader {
    CInstruction::CInstruction() {
        m_Opcode = 0;
        m_uInputs = 0;
        m_pInputs = nullptr;
        m_uOutputs = 0;
        m_pOutputs = nullptr;
        m_uParents = 0;
        m_pParents = nullptr;
        m_uChildren = 0;
        m_pChildren = nullptr;
        m_uMark = 0;
        m_uMark2 = 0;
        m_uPhase = 0;
        m_uRemap = -1;
        m_uBlock = -1;
        m_uNesting = 0;
        m_pExpression = nullptr;
    }

    HRESULT CInstruction::Instance(D3DXShader::CInstruction *insn) {
        if (insn == nullptr) {
            return E_FAIL;
        }
        m_pExpression = insn->m_pExpression;
        return 0;
    }

    uint CInstruction::GetInputs(uint req_inputs, uint **outptr) {
        int opcode_lowpart = m_Opcode & 0x000FFFFF;
        uint whuh = req_inputs * opcode_lowpart;
        if (whuh + opcode_lowpart > m_uInputs) {
            if (outptr != nullptr) {
                *outptr = nullptr;
            }
            return 0;
        }
        if (outptr != nullptr) {
            *outptr = m_pInputs + whuh;
        }
        return opcode_lowpart;
    }

    int CInstruction::IsSpecial() {
        if ((m_Opcode & 0xF0000000) == 0x60000000)
            return true;
        switch (m_Opcode & 0xFFF00000) {
        case 0x50100000:
        case 0x50200000:
        case 0x50300000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsScalar() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x10300000:
        case 0x10500000:
        case 0x10600000:
        case 0x10700000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsSymetric() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x20000000:
        case 0x20100000:
        case 0x20400000:
        case 0x20500000:
        case 0x50000000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsCopy() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x10000000:
        case 0x10100000:
        case 0x11200000:
        case 0x20700000:
        case 0x20800000:
        case 0x20900000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsMacro() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x70700000:
        case 0x50300000:
        case 0x70100000:
        case 0x70200000:
        case 0x70500000:
        case 0x70600000:
        case 0x70B00000:
        case 0x70C00000:
        case 0x70D00000:
        case 0x71000000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsLoop() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x74200000:
        case 0x11500000:
        case 0x11100000:
        case 0x11200000:
        case 0x11300000:
        case 0x11400000:
        case 0x20800000:
        case 0x20900000:
        case 0x74100000:
        case 0x74300000:
        case 0x74400000:
        case 0x74500000:
        case 0x74600000:
        case 0x74700000:
        case 0x74A00000:
        case 0x74B00000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsElse() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x73100000:
        case 0x73300000:
        case 0x73D00000:
        case 0x73E00000:
        case 0x73F00000:
        case 0x74000000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsEndIf() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x20700000:
        case 0x73400000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsFlowControl() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x10F00000:
        case 0x11100000:
        case 0x11200000:
        case 0x11300000:
        case 0x11400000:
        case 0x11500000:
        case 0x20700000:
        case 0x20800000:
        case 0x20900000:
        case 0x73000000:
        case 0x73100000:
        case 0x73200000:
        case 0x73300000:
        case 0x73400000:
        case 0x73500000:
        case 0x73600000:
        case 0x73700000:
        case 0x73800000:
        case 0x73900000:
        case 0x73A00000:
        case 0x73B00000:
        case 0x73C00000:
        case 0x73D00000:
        case 0x73E00000:
        case 0x73F00000:
        case 0x74000000:
        case 0x74100000:
        case 0x74200000:
        case 0x74300000:
        case 0x74400000:
        case 0x74500000:
        case 0x74600000:
        case 0x74700000:
        case 0x74A00000:
        case 0x74B00000:
            return true;
        default:
            return false;
        }
    }

    int CInstruction::IsGradient() {
        switch (m_Opcode & 0xFFF00000) {
        case 0x10D00000:
        case 0x10E00000:
        case 0x60000000:
        case 0x60200000:
        case 0x60300000:
        case 0x60500000:
        case 0x60700000:
        case 0x60800000:
        case 0x60A00000:
        case 0x60C00000:
        case 0x60D00000:
        case 0x60F00000:
        case 0x61100000:
        case 0x61200000:
            return true;
        default:
            return false;
        }
    }

    // void CInstruction::SetAlloc(D3DXCore::CAlloc *) {}
    unsigned int *CInstruction::Alloc(u32) { return nullptr; }
    void *CInstruction::operator new(size_t) { return nullptr; }
    void CInstruction::operator delete(void *) {}
}
