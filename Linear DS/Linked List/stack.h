#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
private:
    int size;
    T* stk;
    T peek;
    int count;
public:
    Stack(int size);
    void push(T data);
    void pop();
    int getCount();
    T getPeek();
    void display();
};
#include "stack.cpp"

#endif