#ifndef MINHEAP_H
#define MINHEAP_H

template <class T>
class MinHeap
{
    T *heapArr int size_;
    int capacity_;
    //returns the index's parent's index
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    //returns the index's left child
    int left(int i)
    {
        return 2 * i + 1;
    }
    // returns the index's right child
    int right(int i)
    {
        return 2 * i + 2;
    }
    void heapifyUp()
    {
    }

    void heapifyDown()
    {
    }
    void resize()
    {
    }

public:
    MinHeap()
    {
    }
};

#endif