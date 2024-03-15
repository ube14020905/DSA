#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data) : data(data), next(nullptr) {}
};

template <class T>
class DLLNode : public Node<T>
{
public:
    Node<T> *prev;
};

template <class T>
class SinglyLinkedList
{
private:
    Node<T> *head;
    int count;

public:
    SinglyLinkedList();
    void append(T data);
    void insert(T data, int pos);
    void pop();
    void remove(int pos);
    void search(T data);
    void display();
    int getCount();
    bool isEmpty() const;
    Node<T> *getHead() const;
    void setHead(Node<T> *newHead);
    void incrementCount();
    void decrementCount();
};

template <class T>
class DoubleLinkedList : public SinglyLinkedList<T>
{
private:
    DLLNode<T> *head;

public:
    DoubleLinkedList();
    void displayFromBack();
    void append(T data);
    void insert(T data, int pos);
    void remove(int pos);
};

template <class T>
class CircularLinkedList : public SinglyLinkedList<T>
{
public:
    void display();
    void append(T data);
    void insert(T data, int pos);
    void remove(int pos);
};

template <class T>
class DoubleCircularLinkedList : public DoubleLinkedList<T>
{
public:
    void displayFromBack();
    void append(T data);
    void insert(T data, int pos);
    void remove(int pos);
};

template <class T>
class Stack : public SinglyLinkedList
{
private:
    Node<T> *top;
    int count;
    T peek;

public:
    Stack();
    void push(T data);
    void pop();
    T getPeek();
    ~Stack();
};

template <class T>
class Queue : public SinglyLinkedList
{
private:
    Node<T> *queue;
    int count;

public:
    Queue();
    void enQue(T data);
    void deQue();
};
#include "SinglyLinkedList.cpp"
#include "Stack.cpp"
#include "CircularDoubleLinkedList.cpp"
#include "CircularLinkedList.cpp"
#include "DoubleLinkedList.cpp"
#include "Queue.cpp"

#endif
