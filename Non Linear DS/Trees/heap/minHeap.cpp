#include <iostream>
#include "heap.h"

using namespace std;

template <class T>
minHeap<T>::minHeap() : root(nullptr), count(0) {}

template <class T>
void collapse(node<T> *n)
{
    if (n->right == nullptr && n->left == nullptr)
    {
        delete n;
    }
    else
    {
        if (n->right == nullptr)
        {
            collapse(n->left);
        }
        else
        {
            collapse(n->right);
        }
    }
}
template <class T>
minHeap<T>::~minHeap()
{
    collapse(root)
}

template <class T>
void minHeap<T>::insert(T data)
{
    node<T> *newNode = new node(data);
    if (root == nullptr)
    {
        root == newNode;
    }
    else
    {
        node<T> *temp = root;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        temp->right = newNode;
        newNode->left = temp;
        heapify(newNode);
    }
    count++;
}
template <class T>
void minHeap<T>::display()
{
    displayRecursive(root);
}
template <class T>
void displayRecursive(node<T> node)
{
    if (node != nullptr)
    {
        displayRecursive(node->left);
        cout << node->data << " ";
        displayRecursive(node->right);
    }
}
template <class T>
void minHeap<T>::remove(T data)
{
    node<T> *current = root;
    while (current != nullptr && current->data != data)
    {
        current = current->right;
    }
    if (current == nullptr)
    {
        return;
    }

    node<T> *lastNode = current;
    while (lastNode->right != nullptr)
    {
        lastNode = lastNode->right;
    }
    std::swap(current->data, lastNode->data);

    if (lastNode->left != nullptr)
    {
        lastNode->left->right = nullptr;
    }
    else
    {
        root = nullptr;
    }
    delete lastNode;

    count--;

    heapify(current);
}

template <class T>
T minHeap<T>::getMin()
{
    if (root == nullptr)
    {
        throw logic_error("Heap is empty");
    }

    return root->data;
}

template <class T>
T minHeap<T>::getMax()
{
    if (root == nullptr)
    {
        throw logic_error("Heap is empty");
    }
    node<T> *current = root;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current->data;
}
