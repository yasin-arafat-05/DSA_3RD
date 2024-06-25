#include<iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int size;
        int top;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }


    void push(int element){
        if(size-top>1){
            arr[top++] = element;
        }else{
            cout<<"stack is overflow"<<endl;
        }
    }



    void pop(){
        if(top>=0){
            top--;
        }else{
            cout<<"stack is underflow"<<endl;
        }
    }


    void peek(){
        if(top>=0){
            cout<<arr[top]<<endl;
        }else{
            cout<<"stack is empty"<<endl;
        }
    }

    void isEmpty(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
    }

};


// ------------------------- implementation of stack ----------------------

int main(){

    Stack st(5);
    st.push(5);
    st.pop();
    st.isEmpty();

}




