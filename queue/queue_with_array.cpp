
#include<iostream>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)};
using namespace std;

class Queue{
    public:
    int size;
    int front;
    int rear;
    int *arr;
    Queue(int size){
        cout<<"Created queue with: "<<size<<endl;
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // _____ push _________
    void push(int data){
        if(rear==size){
            cout<<"queue is full"<<endl;
            return ;
        }
      arr[rear++] = data;  
    }

    // _____ pop _________
    void pop(){
        if(front==rear){
            cout<<"queue is empty"<<endl;
            return ;
        }
        arr[front] = -1;
        front++;
        if(front==rear){
            front=0;
            rear=0;
        }
    }
    // _________ front _____________

    void top(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
            return ;
        }
      cout<<arr[front]<<endl;
    }
    // _________ is_empty _____________

    void isEmpty(){
        if(front==rear){
        cout<<"Queue is empty."<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
    }
    
};

int main(){
    Queue q(5);
    q.push(5);
    q.push(5);
    q.push(5);
    q.push(5);
    q.push(5);
    q.isEmpty();
}