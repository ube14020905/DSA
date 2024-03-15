#include <iostream>

using namespace std;

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), count(0) {}

template <class T>
void SinglyLinkedList<T>::append(T val)
{
    Node<T> *newNode = new Node<T>(val);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    count++;
}

template <class T>
void SinglyLinkedList<T>::insert(T val, int pos)
{
    if (pos < 0 || pos > count)
    {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    Node<T> *newNode = new Node<T>(val);

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node<T> *current = head;
        for (int i = 0; i < pos - 1; ++i)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    count++;
}

template <class T>
void SinglyLinkedList<T>::pop()
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot pop." << endl;
        return;
    }

    if (count == 1)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node<T> *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    count--;
}

template <class T>
void SinglyLinkedList<T>::remove(int pos)
{
    if (pos < 0 || pos >= count)
    {
        cout << "Invalid position for removal." << endl;
        return;
    }

    if (pos == 0)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node<T> *current = head;
        for (int i = 0; i < pos - 1; ++i)
        {
            current = current->next;
        }

        Node<T> *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    count--;
}

template <class T>
void SinglyLinkedList<T>::search(T data)
{
    Node<T> *currentNode = head;
    int pos = 0;
    bool find = false;
    while (currentNode)
    {
        if (currentNode->data == data)
        {
            cout << "The given data " << data << " is present at " << pos << "position" << endl;
            find = true;
        }
        pos++;
        currentNode = currentNode->next;
    }
    if (!find)
    {
        cout << "The Given data is not found in the list!!!" << endl;
    }
}

template <class T>
void SinglyLinkedList<T>::display()
{
    Node<T> *currentNode = head;
    cout << "The Data in Linked List: ";
    while (currentNode)
    {
        cout << currentNode->data << "\t";
        currentNode = currentNode->next;
    }
}

template <class T>
int SinglyLinkedList<T>::getCount()
{
    return count;
}

template <class T>
bool SinglyLinkedList<T>::isEmpty() const
{
    return head == nullptr;
}

template <class T>
Node<T> *SinglyLinkedList<T>::getHead() const
{
    return head;
}

template <class T>
void SinglyLinkedList<T>::setHead(Node<T> *newHead)
{
    head = newHead;
}

template <class T>
void SinglyLinkedList<T>::incrementCount()
{
    count++;
}

template <class T>
void SinglyLinkedList<T>::decrementCount()
{
    count--;
}
