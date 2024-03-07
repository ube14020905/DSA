#ifndef STACK_H
#define STACK_H
template <typename T>
class node
{
public:
    T data;
    node *next;
    node(T data) : data(data), next(nullptr) {}
};
template <typename T>
class Stack
{
private:
    node *top;
    int count;
    T peek;
public:
    Stack();
    void push(T data);
    void pop();
    int getCount();
    T getPeek();
    void display();
};

#endif