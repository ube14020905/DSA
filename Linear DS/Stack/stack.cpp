#include "stack.h"
#include <iostream>
using namespace std;
template <typename T>
Stack<T>::Stack(int size) : size(size),peek(NULL),count(0) {
    stk = new T(size);
}

template <typename T>
void Stack<T>::push(T data)
{
    if(count<size){
        stk[count]=data;
        peek=data;
        count++;
    }
    else{
        cout<<"Stack is full!!!"<<endl;
    }
}
template <typename T>
void Stack<T>::pop()
{
    if (count == 0)
    {
        cout << "The stack is empty!!" << endl;
    }
    else if(count == 1){
        stk[0]=NULL;
        peek=NULL;
        count--;
    }
    else
    {
        peek=stk[count-2];
        stk[count-1]=NULL;
        count--;
    }
}
template <typename T>
int Stack<T>::getCount()
{
    return count;
}

template <typename T>
void Stack<T>::display()
{
    cout<<"Stack Elements: "<<endl;
    for(int i=count-1;i>=0;i--){
        cout<<stk[i]<<endl;
    }
}

template <typename T>
T Stack<T>::getPeek()
{
    return peek;
}