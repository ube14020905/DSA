#include <iostream>
using namespace std;
template <class T>
Stack<T>::Stack(int size) : size(size),peek(T()),count(0) {
    stk = new T[size];
}

template <class T>
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
template <class T>
void Stack<T>::pop()
{
    if (count == 0)
    {
        cout << "The stack is empty!!" << endl;
    }
    else if(count == 1){
        stk[0]=T();
        peek=T();
        count--;
    }
    else
    {
        peek=stk[count-2];
        stk[count-1]=T();
        count--;
    }
}
template <class T>
int Stack<T>::getCount()
{
    return count;
}

template <class T>
void Stack<T>::display()
{
    cout<<"Stack Elements: "<<endl;
    for(int i=count-1;i>=0;i--){
        cout<<stk[i]<<endl;
    }
}

template <class T>
T Stack<T>::getPeek()
{
    return peek;
}