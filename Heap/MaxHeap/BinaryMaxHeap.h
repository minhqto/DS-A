#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <algorithm>

// The binary max heap is a tree-based priority queue data strcture that prioritizes the greatest value.
template <class T>
class BinaryMaxHeap
{

    T *heapArr;
    int size_;
    int parent(int i)
    {
        return (i - 1) / 2; //no need to floor because c++ floors by default
    }
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    void heapifyUp(int idx)
    {
        //base case. when the curr element is less than it's parent
        if (idx && this->heapArr[idx] > this->heapArr[this->parent(idx)])
        {
            std::swap(this->heapArr[idx], this->heapArr[this->parent(idx)]);
            heapifyUp(this->parent(idx));
        }
    }
    bool search(const T &data)
    {
        for (int i = 0; i < this->size_; i++)
        {
            if (this->heapArr[i] == data)
            {
                return true;
            }
        }
        return false;
    }

    void heapifyDown(int idx)
    {
        //base case: when the curr element is greater than both of it's parents
        int largest = idx;
        //check left child
        if (this->heapArr[idx] < this->heapArr[this->left(idx)])
        {
            largest = this->heapArr[this->left(idx)];
        }
        //check right child
        if (this->heapArr[this->right(idx)] > largest)
        {
            largest = this->heapArr[this->right(idx)];
        }

        if (largest != idx)
        {
            std::swap(this->heapArr[largest], this - heapArr[idx]);
            heapifyDown(largest);
        }
    }

public:
    BinaryMaxHeap()
    {
        this->heapArr = nullptr;
        this->size_ = 0;
    }
    void insert(T data)
    {
        if (this->size_ == 0)
        {
            this->heapArr = new T[++this->size_];
            this->heapArr[this->size_ - 1] = data;
        }
        else
        {
            T *temp = new T[this->size_];
            for (int i = 0; i < this->size_; i++)
            {
                temp[i] = this->heapArr[i];
            }
            this->heapArr = new T[++this->size_];
            for (int i = 0; i < this->size_ - 1; i++)
            {
                this->heapArr[i] = temp[i];
            }

            //insert at the end of the heap. then heapify
            this->heapArr[this->size_ - 1] = data;
            this->heapifyUp(this->size_ - 1);
        }
    }
    T &getMax()
    {
        return this->heapArr[0];
    }

    void deleteNode(const T &data)
    {
        if (this->search(data))
        {
        }
        else
        {
            std::cout << "Element does not exist!" << std::endl;
        }
    }
    bool isEmpty()
    {
        return this->size_ == 0;
    }
    void displayHeap()
    {
        for (int i = 0; i < this->size_; i++)
        {
            std::cout << this->heapArr[i] << std::endl;
        }
    }
};
#endif