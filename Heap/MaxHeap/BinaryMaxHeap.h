#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <algorithm>

// The binary max heap is a tree-based priority queue data strcture that prioritizes the greatest value.
template <class T>
class BinaryMaxHeap
{
    //decided to use dynamically allocated memory instead of a vector, just for a greater challenge
    T *heapArr;
    int size_;
    int capacity;
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

    void heapifyDown(int idx)
    {
        int largest = idx;
        //check left child
        if (this->heapArr[idx] < this->heapArr[this->left(idx)])
        {
            largest = this->left(idx);
        }
        //check right child
        if (this->heapArr[this->right(idx)] > this->heapArr[largest])
        {
            largest = this->right(idx);
        }
        // must check that the idx named largest isn't greater than the size of the heap, otherwise it will pull in "deleted" data
        if (largest <= this->size_ && largest != idx)
        {
            std::swap(this->heapArr[largest], this->heapArr[idx]);
            heapifyDown(largest);
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

    void resize()
    {
        this->capacity += 10;
        T *temp = new T[this->size_];
        for (int i = 0; i < this->size_; i++)
        {
            temp[i] = this->heapArr[i];
        }

        delete[] this->heapArr;
        this->heapArr = nullptr;
        this->heapArr = new T[this->capacity];

        for (int i = 0; i < this->size_; i++)
        {
            this->heapArr[i] = temp[i];
        }
        delete[] temp;
        std::cout << "Heap can now hold " << this->capacity << " elements" << std::endl;
    }

public:
    BinaryMaxHeap()
    {
        this->capacity = 10;
        this->heapArr = new T[this->capacity];
        this->size_ = 0;
    }
    void insert(T data)
    {
        if (this->size_ == 0)
        {
            this->heapArr[this->size_++] = data;
        }
        else if (this->size_ < this->capacity)
        {
            this->heapArr[this->size_++] = data;
            this->heapifyUp(this->size_ - 1);
        }
        else if (this->size_ >= this->capacity)
        {
            this->resize();
            this->heapArr[this->size_++] = data;
            this->heapifyUp(this->size_ - 1);
        }
    }
    T &getMax()
    {
        return this->heapArr[0];
    }

    void deleteMax()
    {
        if (!this->isEmpty())
        {
            T temp = this->heapArr[0];
            //remove the top node. replace the top node with the most recent node. heapifyDown
            this->heapArr[0] = this->heapArr[--this->size_];
            this->heapifyDown(0);
            std::cout << "Element " << temp << " deleted!" << std::endl;
        }
        else
        {
            std::cout << "Heap is empty!" << std::endl;
        }
    }
    bool isEmpty()
    {
        return this->size_ == 0;
    }

    int getSize()
    {
        return this->size_;
    }
    void displayHeap()
    {
        if (!this->isEmpty())
        {
            for (int i = 0; i < this->size_; i++)
            {
                std::cout << this->heapArr[i] << std::endl;
            }
        }
        else
        {
            std::cout << "Heap is empty!" << std::endl;
        }
    }
};
#endif