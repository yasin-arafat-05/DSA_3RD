
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
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // push 
    void push()

};