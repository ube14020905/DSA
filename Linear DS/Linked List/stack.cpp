#include "LinkedList.h"
#include <iostream>
using namespace std;
template <typename T>
Stack<T>::Stack() : top(nullptr), count(0), peek(NULL) {}

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
        newNode->next = top;
        top = newNode;
    }
    peek = data;
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
        top=nullptr;
        peek = NULL;
        count--;
    }
    else
    {
        node<T> newTop = top->next;
        delete top;
        top = newTop;
        peek = top->data;
        count--;
    }
}
template <typename T>
T Stack<T>::getPeek()
{
    return peek;
}
template <typename T>
Stack<T>::~Stack()
{
    while (top != nullptr)
    {
        node<T> *temp = top;
        top = top->next;
        delete temp;
    }
}
