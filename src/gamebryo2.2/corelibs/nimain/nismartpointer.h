#pragma once

template <typename T>
class NiPointer {
public:
    NiPointer(NiPointer<T> const &);

    NiPointer(T *pObject) : m_pObject(pObject) {
        if (pObject) {
            pObject->IncRefCount();
        }
    }

    ~NiPointer() {
        if (m_pObject) {
            m_pObject->DecRefCount();
        }
    }

    operator T *() const { return m_pObject; }

    T &operator*() const { return *m_pObject; }

    T *operator->() const { return m_pObject; }

    NiPointer<T> &operator=(T *pObject); /* {
        if (m_pObject) {
            m_pObject->DecRefCount();
        }
        m_pObject = pObject;
        if (pObject) {
            pObject->IncRefCount();
        }
    }*/

    NiPointer<T> &operator=(NiPointer<T> const &rhs); /* {
         if (m_pObject) {
             m_pObject->DecRefCount();
         }
         m_pObject = rhs.m_pObject;
         if (m_pObject) {
             m_pObject->IncRefCount();
         }
     }*/

    bool operator==(NiPointer<T> const &rhs) const { return m_pObject == rhs.m_pObject; }

    bool operator==(T *pPointer) const { return m_pObject == pPointer; }

    bool operator!=(NiPointer<T> const &rhs) const { return !(this == rhs); }

    bool operator!=(T *pObject) const { return !(this == pObject); }

    T *m_pObject; // 0x0
};
