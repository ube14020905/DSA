#include "stack.h"
#include <iostream>
template<typename T>
Stack<T>::Stack():top(nullptr),count(0){}

template<typename T>
void Stack<T>::push(T data){
    node<t> *newNode=new node(data);
    if(top==nullptr){
        top=newNode;
    }
    else{
        node<T> *current=top;
        while(current->next!=nullptr){
            current=current->next;
        }
        current->next=newNode;
    }
    count++;
}
