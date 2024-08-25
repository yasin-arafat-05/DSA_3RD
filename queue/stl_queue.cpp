
#include<iostream>
#include<queue>
using namespace std; 

int main(){
    queue<int> q;
    q.push(8);
    q.push(9);

    // size()
    cout<<"size of queue : "<< q.size()<<endl;

    // front()
    cout<<"front: "<<q.front()<<endl;

    // empty()
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
    // pop()
    q.pop();
    cout<<"size of queue : "<< q.size()<<endl;

    // 

}