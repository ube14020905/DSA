#include<iostream>

using namespace std;

template <class T>
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

template <class T>
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
        Node<T> *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
    this->incrementCount();
}

template <class T>
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
        newNode->next = head;
        head=newNode;

        Node<T> *last =head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = newNode;
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
    this->incrementCount();
}

template <class T>
void CircularLinkedList<T>::remove(int pos)
{
    if (pos < 0 || pos >= this->getCount())
    {
        cout << "Invalid position for removal." << endl;
        return;
    }

    if (pos == 0)
    {
        Node<T> *temp = head;
        head=head->next;
        Node<T> *last = head;
        while (last->next != temp)
        {
            last = last->next;
        }
        last->next = head;

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
    this->decrementCount();
}
