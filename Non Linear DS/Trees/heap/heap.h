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
    template <class T>
    void heapify(node<T> *current)
    {
        if (current == nullptr)
            return;

        node<T> *smallest = current;

        if (current->left != nullptr && current->left->data < smallest->data)
            smallest = current->left;

        if (current->right != nullptr && current->right->data < smallest->data)
            smallest = current->right;

        if (smallest != current)
        {
            std::swap(current->data, smallest->data);
            heapify(smallest);
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
    int count;
    template <class T>
    void heapify(node<T> *current)
    {
        if (current == nullptr)
            return;

        node<T> *largest = current;

        if (current->left != nullptr && current->left->data > largest->data)
            largest = current->left;

        if (current->right != nullptr && current->right->data > largest->data)
            largest = current->right;
        if (largest != current)
        {
            std::swap(current->data, largest->data);
            heapify(largest);
        }
    }

public:
    maxHeap();
    ~maxHeap();
    void insert(T data);
    void remove(T data);
    T getMax();
    T getMin();
    void display() override;
};
template <class T>
void collapse(node<T> *n);
template <class T>
void displayRecursive(node<T> node);
#include "minHeap.cpp"
#include "maxHeap.cpp"
#endif