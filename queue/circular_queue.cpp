
#include<iostream>
using namespace std;

class CircularQ{
    public:
        int front;
        int rear;
        int *arr;
        int size;
    CircularQ(int n){
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];


    }

    void insert(int data){
        if((rear+1==front || (front==0 && rear==(size-1)))){
            cout<<"Queue is full"<<endl;
            return ;
        }
        if(rear==-1){
            front++;
            rear++;
        }else if(rear==(size-1) && front!=0){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear]=data;
    }

    int deletion(){
        if(front==-1 || rear==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ret = arr[front];
        arr[front] = -1;
        if(front==rear){
            front = -1;
            rear = -1;
        }else if(front==size-1){
            front = 0;
        }else{
            front++;
        }
        return ret;
    }

};

int main(){

    CircularQ q(5); 

    // Insert elements
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);
    q.insert(50); 

    // Try to insert one more element to check the full condition
    q.insert(60);

    // Delete a few elements
    cout<<q.deletion()<<endl;
    cout<< q.deletion()<<endl;

    // Insert more elements after deletion to check circular behavior
    q.insert(60);
    q.insert(70);

    // Try to insert one more element to ensure it's full
    q.insert(80);

    return 0;
}


