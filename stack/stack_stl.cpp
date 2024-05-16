#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> st;
    st.push(1);
    cout<<"top element of stack: "<<st.top()<<endl;
    st.pop();
    cout<<"is stack empty: "<< boolalpha<<st.empty()<<endl;
}