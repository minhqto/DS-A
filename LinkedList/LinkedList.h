#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class List
{

    struct Node
    {
        int data_;
        Node *next;
        Node *prev;
        Node() : data_(0), next(nullptr), prev(nullptr) {}
        Node(int d, Node *n, Node *p) : data_(d), next(n), prev(p) {}
    };

    Node *head_;
    Node *tail_;

public:
    List();
    void insert(int);
    Node *find(int);
    void remove(int);
    void display();
    ~List();
    //normally will require copy constructor and assignment operator in order to follow the rule of 3, but excluding them for brevity.
};

#endif