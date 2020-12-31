#include "LinkedList.h"

List::List()
{
    this->head_ = nullptr;
    this->tail_ = nullptr;
}

void List::insert(int d)
{
    Node *newNode = new Node(d, nullptr, nullptr);

    if (this->head_ == nullptr)
    {
        this->head_ = newNode;
        this->tail_ = newNode;
    }
    else
    {
        newNode->prev = this->tail_;
        this->tail_->next = newNode;
        this->tail_ = newNode;
    }
}

List::Node *List::find(int d)
{
    Node *temp = this->head_;
    while (temp != nullptr)
    {
        if (temp->data_ == d)
        {
            return temp;
        }
        temp = temp->next;
    }

    return temp;
}
void List::remove(int d)
{
    //traverse the list and find the node with that data
    Node *temp = this->find(d);
    if (temp != nullptr)
    {
        if (temp == this->head_)
        {
            this->head_ = this->head_->next;
            delete temp;    
        }
        else if (temp == this->tail_)
        {
            this->tail_ = this->tail_->prev;
            this->tail_->next = nullptr;
            delete temp;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
    else
    {
        std::cout << "Node does not exist!" << std::endl;
    }
}

void List::display()
{
    if (this->head_ == nullptr)
    {
        std::cout << "List is empty!" << std::endl;
    }
    else
    {
        Node *temp = this->head_;
        while (temp != nullptr)
        {
            std::cout << temp->data_ << std::endl;
            temp = temp->next;
        }
    }
}

List::~List()
{
    while (this->head_ != nullptr)
    {
        Node *temp = this->head_;
        this->head_ = this->head_->next;
        delete temp;
    }
}
