#include<iostream>
#include<stack>
#include<queue>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;

int main(){

    //____________ stack with stl __________
    cout<<"stack"<<endl;
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    //____________  queue with stl __________

    cout<<"queue"<<endl;
    queue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    
}