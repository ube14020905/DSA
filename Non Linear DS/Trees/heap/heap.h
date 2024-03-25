#ifndef HEAP_H
#define HEAP_H

template <class T>
class node
{
public:
    T data;
    node<T> *right;
    node<T> *left;
    node(T data) : data(data), left(nullptr), right(nullptr) {}
};
template <class T>
class heap
{
public:
    void display() {}
};
template <class T>
class minHeap : public heap<T>
{
private:
    node<T> *root;
    void heapify(node<T> newNode)
    {
        node<T> *current = newNode;
        while (current->left != nullptr && current->left->data > current->data)
        {
            swap(current->data, current->left->data);
            current = current->left;
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
    void heapify(node<T> newNode)
    {
        node<T> *current = newNode;
        while (current->left != nullptr && current->left->data < current->data)
        {
            swap(current->data, current->left->data);
            current = current->left;
        }
    }
    int count;

public:
    maxHeap();
    ~maxHeap();
    void insert(T data);
    void remove(T data);
    T getMax();
    T getMin();
    void display() override;
};
template<class T>
void collapse(node<T>* n);
template <class T>
void displayRecursive(node<T> node);
#include "minHeap.cpp"
#endif