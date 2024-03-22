#include<iostream>
#include "heap.h"

using namespace std;

template<class T>
minHeap<T>::minHeap():root(nullptr),count(0){}

template<class T>
void minHeap<T>::insert(T data){
    node<T>* newNode = new node(T);
    if (root==nullptr){
        root == newNode;
    }else{
                node<T> *temp = root;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        heapify(newNode);
    }
    count++;
}
template<class T>
void minHeap<T>::display(){
    displayRecursive(root);
}
template<class T>
void displayRecursive(node<T> node){
    if (node != nullptr)
    {
        display(node->left);
        cout << node->data << " ";
        (node->right);
    }
}
template <class T>
void minHeap<T>::remove(T data) {
    node<T> *current = root;
    while (current != nullptr && current->data != data) {
        current = current->next;
    }
    if (current == nullptr) {
        return;
    }

    node<T> *lastNode = current;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    std::swap(current->data, lastNode->data);

    if (lastNode->prev != nullptr) {
        lastNode->prev->next = nullptr;
    } else {
        root = nullptr;
    }
    delete lastNode;

    count--;

    heapify(current);
}

template <class T>
T minHeap<T>::getMin() {
    if (root == nullptr) {
        throw std::logic_error("Heap is empty");
    }

    return root->data;
}

template <class T>
T minHeap<T>::getMax() {
    if (root == nullptr) {
        throw std::logic_error("Heap is empty");
    }

    node<T> *current = root;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current->data;
}
