#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class DLLNode : public Node<T>
{
public:
    Node<T> *prev;
};

template <typename T>
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

template <typename T>
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

template <typename T>
class CircularLinkedList : public SinglyLinkedList<T>
{
public:
    void display();
    void append(T data);
    void insert(T data, int pos);
    void remove(int pos);
};

template <typename T>
class DoubleCircularLinkedList : public DoubleLinkedList<T>
{
public:
    void displayFromBack();
    void append(T data);
    void insert(T data, int pos);
    void remove(int pos);
};

template <typename T>
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

template <typename T>
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

#endif
