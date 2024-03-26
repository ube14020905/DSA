#include"stack.h"
#include<iostream>
using namespace std;
int main(){
    Stack<int> st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.display();
    cout<<st.getPeek()<<endl;
    return 0;
}