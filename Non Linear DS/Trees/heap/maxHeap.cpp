#include <iostream>
#include "heap.h"
using namespace std;

template <class T>
maxHeap<T>::maxHeap() : root(nullptr), count(0) {}
template <class T>
maxHeap<T>::~maxHeap()
{
    collapse(root);
}

template <class T>
void maxHeap<T>::insert(T data)
{
    node<T> *newNode = new node(data);
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        node<T> *temp = root;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        heapify(newNode);
    }
    count++;
}
template <class T>
void maxHeap<T>::display()
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