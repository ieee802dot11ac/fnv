#pragma once

#include "nimain/NiTStringMap.h"
template <typename T>
class BSTCaseInsensitiveStringMap : public NiTStringMap<T> {
public:
    BSTCaseInsensitiveStringMap(const BSTCaseInsensitiveStringMap<T> &);
    BSTCaseInsensitiveStringMap(unsigned int, bool);
    virtual ~BSTCaseInsensitiveStringMap();

protected:
    virtual unsigned int KeyToHashIndex(const T) const;
    virtual bool IsKeysEqual(const T, const T) const;
};
