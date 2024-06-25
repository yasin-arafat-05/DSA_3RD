#include<iostream>
using namespace std;

int main(){
    int *n;
    int x = 'A';
    n = &x;

    cout<< *n << endl;

    delete n;

    cout << (n+1)<<endl;
    cout << (n+2)<<endl;
    cout << (n+3)<<endl;
    cout << (n+4)<<endl;
    cout << (n+5)<<endl;
}