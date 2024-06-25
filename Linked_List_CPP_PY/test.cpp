#include<iostream>
using namespace std;

void func(int x){
    if(x==5){
        cout<<"x is equal to 5"<<endl;
       return;
    }

    cout<<"next-> "<<endl;
}
int main(){
    int x = 5;
    func(x);
}