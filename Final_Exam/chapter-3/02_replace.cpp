


#include<iostream>
#include<string>
using namespace std;


int main(){

    string t,p,q;

    cout<<"Enter a text: "<<endl;
    getline(cin,t);

    cout<<"Enter a pattern: "<<endl;
    getline(cin,p);

    cout<<"Enter replace pattern: "<<endl;
    getline(cin,q);

    int fnd = t.find(p);
    while(fnd != -1){
        t.replace(fnd,p.size(),q);
        fnd = t.find(p);
    }

    cout<<" result: "<<t<<endl;

}


