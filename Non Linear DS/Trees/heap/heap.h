#ifndef HEAP_H
#define HEAP_H

template <class T>
class node
{
public:
    T data;
    node<T> *next;
    node<T> *prev;
    node(T data) : data(data), next(nullptr), prev(nullptr) {}
};
template <class T>
class heap
{
public:
    void display(){}
};
template <class T>
class minHeap : public heap<T>
{
private:
    node<T> *root;
    void heapify(node<T> newNode)
    {
        node<T> *current = newNode;
        while (current->prev != nullptr && current->prev->data > current->data)
        {
            swap(current->data, current->prev->data);
            current = current->prev;
        }
    }
    int count;

public:
    minHeap();
    ~minHeap();
    void insert(T data);
    void remove(T data);
    void display() override;
    T getMax();
    T getMin();
};

template <class T>
class maxHeap : public heap<T>
{
private:
    node<T> *root;
    void heapify(node<T> newNode);
    int count;

public:
    maxHeap();
    ~maxHeap();
    void insert(T data);
    void remove(T data);
    T getMax();
    T getMin();
    void display() const override;
};
#include "minHeap.cpp"
#endif