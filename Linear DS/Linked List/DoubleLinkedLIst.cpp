#include "LinkedList.h"

using namespace std;

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : SinglyLinkedList<T>(), head(nullptr) {}

template <typename T>
void DoubleLinkedList<T>::displayFromBack()
{
    DLLNode<T> *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    cout << "Data in Double Linked List (from back): ";
    while (current != nullptr)
    {
        cout << current->data << "\t";
        current = current->prev;
    }
    cout << endl;
}

template <typename T>
void DoubleLinkedList<T>::append(T data)
{
    DLLNode<T> *newNode = new DLLNode<T>;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        DLLNode<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    this->incrementCount();
}

template <typename T>
void DoubleLinkedList<T>::insert(T data, int pos)
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
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    else
    {
        DLLNode<T> *current = head;
        for (int i = 0; i < pos - 1; ++i)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
    this->incrementCount();
}

template <typename T>
void DoubleLinkedList<T>::remove(int pos)
{
    if (pos < 0 || pos >= this->getCount())
    {
        cout << "Invalid position for removal." << endl;
        return;
    }

    if (pos == 0)
    {
        DLLNode<T> *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
    }
    else
    {
        DLLNode<T> *current = head;
        for (int i = 0; i < pos - 1; ++i)
        {
            current = current->next;
        }

        DLLNode<T> *temp = current->next;
        current->next = current->next->next;
        if (current->next != nullptr)
        {
            current->next->prev = current;
        }
        delete temp;
    }
    this->decrementCount();
}
