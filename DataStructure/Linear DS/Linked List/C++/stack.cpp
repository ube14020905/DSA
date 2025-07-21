
#include <iostream>
using namespace std;
template <class T>
Stack<T>::Stack() : top(nullptr), count(0), peek(T()) {}

template <class T>
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
template <class T>
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
        peek = T();
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
template <class T>
T Stack<T>::getPeek()
{
    return peek;
}
template <class T>
Stack<T>::~Stack()
{
    while (top != nullptr)
    {
        node<T> *temp = top;
        top = top->next;
        delete temp;
    }
}
