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
class heap
{
public:
    void display() const;
};
template <class T>
class minHeap : public heap<T>
{
private:
    node<T> *root;
    void heapify(node<T> newNode);
    int count;

public:
    minHeap();
    ~minHeap();
    void insert(T data);
    void remove(T data);
    T getMax();
    T getMin();
};

template <class T>
class maxHeap : public heap<T>{
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
};
#endif