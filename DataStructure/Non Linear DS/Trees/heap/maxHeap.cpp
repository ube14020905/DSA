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
template <class T>
void maxHeap<T>::remove(T data)
{
    node<T> *current = root;
    node<T> *parent = nullptr;
    while (current != nullptr && current->data != data)
    {
        parent = current;
        if (data > current->data)
            current = current->right;
        else
            current = current->left;
    }

    if (current == nullptr)
        return;

    node<T> *lastParent = nullptr;
    node<T> *last = root;
    while (last->left != nullptr || last->right != nullptr)
    {
        lastParent = last;
        if (last->right != nullptr && last->right->right != nullptr)
            last = last->right;
        else
            last = last->left;
    }

    std::swap(current->data, last->data);

    if (lastParent == nullptr)
    {
        delete last;
        root = nullptr;
        return;
    }

    if (lastParent->left == last)
        lastParent->left = nullptr;
    else
        lastParent->right = nullptr;

    delete last;

    heapify(root);
}
template<class T>
T maxHeap<T>::getMax(){
    if(root!== nullptr){
        return root->data;
    }
    throw logic_error("heap is empty");
}
template<class T>
T maxHeap<T>::getMin(){
    if(root== nullptr){
    throw logic_error("heap is empty");
    }
    node<T>* current=root;
    while(current->left !=nullptr){
        current=current->left;
    }
    return current->data;
}