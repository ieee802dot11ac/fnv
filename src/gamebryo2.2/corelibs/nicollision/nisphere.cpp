#include "nisphere.h"
#include "nimain/nistream.h"

bool NiSphere::operator==(const NiSphere &kSphere) const {
    return m_kCenter == kSphere.m_kCenter && m_fRadius == kSphere.m_fRadius ? 1 : 0;
}

void NiSphere::SaveBinary(NiStream &kStream) {
    m_kCenter.SaveBinary(kStream);
    NiStreamSaveBinary(kStream, m_fRadius);
}
