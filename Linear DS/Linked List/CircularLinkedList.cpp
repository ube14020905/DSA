#include "LinkedList.h"

using namespace std;

template <typename T>
void CircularLinkedList<T>::display()
{
    if (this->isEmpty())
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node<T> *current = this->getHead();
    cout << "Data in Circular Linked List: ";
    do
    {
        cout << current->data << "\t";
        current = current->next;
    } while (current != this->getHead());
    cout << endl;
}

template <typename T>
void CircularLinkedList<T>::append(T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->next = nullptr;

    if (this->isEmpty())
    {
        this->setHead(newNode);
        newNode->next = newNode;
    }
    else
    {
        Node<T> *last = this->getHead();
        while (last->next != this->getHead())
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = this->getHead();
    }
    this->incrementCount();
}

template <typename T>
void CircularLinkedList<T>::insert(T data, int pos)
{
    if (pos < 0 || pos > this->getCount())
    {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    Node<T> *newNode = new Node<T>(data);
    newNode->next = nullptr;

    if (pos == 0)
    {
        newNode->next = this->getHead();
        this->setHead(newNode);

        Node<T> *last = this->getHead();
        while (last->next != this->getHead())
        {
            last = last->next;
        }
        last->next = newNode;
    }
    else
    {
        Node<T> *current = this->getHead();
        for (int i = 0; i < pos - 1; ++i)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->incrementCount();
}

template <typename T>
void CircularLinkedList<T>::remove(int pos)
{
    if (pos < 0 || pos >= this->getCount())
    {
        cout << "Invalid position for removal." << endl;
        return;
    }

    if (pos == 0)
    {
        Node<T> *temp = this->getHead();
        this->setHead(this->getHead()->next);

        Node<T> *last = this->getHead();
        while (last->next != temp)
        {
            last = last->next;
        }
        last->next = this->getHead();

        delete temp;
    }
    else
    {
        Node<T> *current = this->getHead();
        for (int i = 0; i < pos - 1; ++i)
        {
            current = current->next;
        }

        Node<T> *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    this->decrementCount();
}
