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
public:
    Stack();
    void push(T data);
    void pop();
    int getCount();
    T peek();
    void display();
};

#endif