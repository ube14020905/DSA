#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
Queue<T>::Queue() : queue(nullptr), count(0) {}

template <typename T>
void Queue<T>::enQue(T data)
{
    Node<T> newNode = new Node(data);
    if (count == 0)
    {
        queue = newNode;
    }
    else
    {
        newNode->next = queue;
        queue = newNode;
    }
    count++;
}
template <typename T>
void Queue<T>::deQue()
{
    if (count == 0)
    {
        cerr << "The Queue is empty" << endl;
    }
    if (count == 1)
    {
        delete queue;
        queue = nullptr;
    }
    else
    {
        Node<T> *current = queue;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    count--;
}