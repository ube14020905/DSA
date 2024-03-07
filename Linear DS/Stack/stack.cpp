#include "stack.h"
#include <iostream>
using namespace std;
template <typename T>
Stack<T>::Stack() : top(nullptr), count(0) {}

template <typename T>
void Stack<T>::push(T data)
{
    node<t> *newNode = new node(data);
    if (top == nullptr)
    {
        top = newNode;
    }
    else
    {
        node<T> *current = top;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    peek=data;
    count++;
}
template <typename T>
void Stack<T>::pop()
{
    if (count == 0)
    {
        cout << "The stack is empty!!" << endl;
    }
    if (count == 1)
    {
        delete top;
        peek=NULL;
        count--;
    }
    else
    {
        node<T> current = top;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        delete current;
        count--;
    }
}
template <typename T>
int Stack<T>::getCount()
{
    return count;
}

template <typename T>
void Stack<T>::display()
{
    node<T> *current = top;
    cout << "The data present in stack: ";
    while (current != nullptr)
    {
        cout << current->data << "\t";
        current = current->next;
    }
}

template<typename T>
T Stack<T>::getPeek(){
    return peek;
}