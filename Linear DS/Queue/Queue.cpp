#include "Queue.h"
#include <iostream>

using namespace std;

template <typename T>
Queue<T>::Queue(int size) : size(size), count(0)
{
    queue = new T(size);
}
template <typename T>
void Queue<T>::enQue(T data)
{
    if (count < size)
    {
        queue[count] = data;
        count++;
    }
    else
    {
        cerr << "Queue is full!!!" << endl;
    }
}
template <typename T>
void Queue<T>::deQue()
{
    if (count == 0)
    {
        cerr << "Queue is Empty!!!" << endl;
    }
    else
    {
        cout << queue[0] << "is removed!!!" << endl;
        queue[0] == NULL;
        for (int i = 0; i < count + 1; i++)
        {
            queue[i + 1] = queue[i];
        }
    }
}
template <typename T>
void Queue<T>::display()
{
    if (count == 0)
    {
        cout << "Queue is empty!!!" << endl;
        return;
    }
    cout<<"Queue Elements: ";
    for(int i=0;i<count;i++){
        cout<<queue[i]<<"\t";
    }
    cout<<endl;
}