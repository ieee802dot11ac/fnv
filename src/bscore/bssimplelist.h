#pragma once

template <typename T>
class BSSimpleList {
public:
    BSSimpleList(T *&);
    BSSimpleList();
    ~BSSimpleList();
    void SetItem(T *&);
    T *&GetItem();
    T *&GetItem() const;
    void SetNext(BSSimpleList<T *> *);
    BSSimpleList<T *> *GetNext() const;
    bool IsEmpty() const;
    bool IsInList(T *&) const;
    unsigned int ItemsInList() const;
    void AddHead(T *&);
    void Remove(T *&);
    void RemoveHead();
    void RemoveAll();
    void AddTail(T *&);
    void Sort(int (*)(T *, T *));
    void Insert(T *, int (*)(T *, T *));
    void Traverse(bool (*)(T *, unsigned int), unsigned int);

protected:
    T *m_item; // 0x0
    BSSimpleList<T *> *m_pkNext; // 0x4

private:
    BSSimpleList(const BSSimpleList<T *> &);
    BSSimpleList<T *> &operator=(const BSSimpleList<T *> &);
    void BubbleSort(int (*)(T *, T *));
    void ShellSort(T **, int (*)(T *, T *), int);
    void QuickSort(T **, int (*)(T *, T *), int, int);
    int Partition(T **, int (*)(T *, T *), int, int);
};
