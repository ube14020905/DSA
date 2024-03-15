#include<iostream>
using namespace std;

template <class T>
void DoubleCircularLinkedList<T>::displayFromBack()
{
    if (this->isEmpty())
    {
        cout << "The list is empty." << endl;
        return;
    }

    DLLNode<T> *current = this->getHead()->prev;
    cout << "Data in Double Circular Linked List (from back): ";
    do
    {
        cout << current->data << "\t";
        current = current->prev;
    } while (current != this->getHead()->prev);
    cout << endl;
}

template <class T>
void DoubleCircularLinkedList<T>::append(T data)
{
    DLLNode<T> *newNode = new DLLNode<T>;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (this->isEmpty())
    {
        this->setHead(newNode);
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        DLLNode<T> *current = this->getHead()->prev;
        current->next = newNode;
        newNode->prev = current;
        newNode->next = this->getHead();
        this->getHead()->prev = newNode;
    }
    this->incrementCount();
}

template <class T>
void DoubleCircularLinkedList<T>::insert(T data, int pos)
{
    if (pos < 0 || pos > this->getCount())
    {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    DLLNode<T> *newNode = new DLLNode<T>;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (pos == 0)
    {
        newNode->next = this->getHead();
        newNode->prev = this->getHead()->prev;
        this->getHead()->prev->next = newNode;
        this->getHead()->prev = newNode;
        this->setHead(newNode);
    }
    else
    {
        DLLNode<T> *current = this->getHead()->prev;
        for (int i = 0; i < pos - 1; ++i)
        {
            current = current->prev;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
    this->incrementCount();
}

template <class T>
void DoubleCircularLinkedList<T>::remove(int pos)
{
    if (pos < 0 || pos >= this->getCount())
    {
        cout << "Invalid position for removal." << endl;
        return;
    }

    if (pos == 0)
    {
        DLLNode<T> *temp = this->getHead();
        this->getHead()->prev->next = this->getHead()->next;
        this->getHead()->next->prev = this->getHead()->prev;
        this->setHead(this->getHead()->next);

        delete temp;
    }
    else
    {
        DLLNode<T> *current = this->getHead()->prev;
        for (int i = 0; i < pos - 1; ++i)
        {
            current = current->prev;
        }

        DLLNode<T> *temp = current->next;
        current->next = current->next->next;
        current->next->prev = current;

        delete temp;
    }
    this->decrementCount();
}

