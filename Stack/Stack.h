#ifndef STACK_H
#define STACK_H
#include <iostream>

template <class T>
class Stack
{
    T *daStack;
    int size;

public:
    Stack() : daStack(nullptr), size(0) {} //member initializer lists. Save the program from having to initialize data twice
    ~Stack()
    {
        delete[] daStack;
    }
    void push(T _data)
    {
        if (this->size == 0)
        {

            this->daStack = new T[++this->size];
            this->daStack[this->size - 1] = _data;
        }
        else
        {
            T *temp = new T[this->size];
            for (int i = 0; i < this->size; i++)
            {
                temp[i] = this->daStack[i];
            }

            delete[] this->daStack;
            this->daStack = new T[++this->size];

            for (int i = 0; i < this->size - 1; i++)
            {
                this->daStack[i] = temp[i];
            }

            this->daStack[this->size - 1] = _data;
        }
    }
    void pop()
    {
        this->size--;
    }

    T &peek()
    {
        return this->daStack[this->size - 1];
    }

    int &getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->size == 0 ? true : false;
    }

    void printStack()
    {
        if (this->size == 0)
        {
            std::cout << "Stack is empty!" << std::endl;
        }
        for (int i = 0; i < this->size; i++)
        {
            std::cout << this->daStack[i] << std::endl;
        }
    }
};

#endif