#ifndef HEAP_H
#define HEAP_H

template <class T>
class node
{
public:
    T data;
    node<T> *next;
    node<T> *prev;
};
template <class T>
class minHeap
{
private:
    node<T> root;
    void heapify(node<T> newNode);
    int count;
public:
    minHeap();
    ~minHeap();
    void insert(T data);
    void remove(T data);
    void display();
    T getMax();

};
#endif