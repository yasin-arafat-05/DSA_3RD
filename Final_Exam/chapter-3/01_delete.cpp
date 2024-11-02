

#include<iostream>
#include<string>
using namespace std;

int main(){
    string t;
    string p;
    cout<<"Enter a Text: "<<endl;
    getline(cin,t);
    cout<<"Enter a Pattern: "<<endl;
    getline(cin,p);
    
    int index = t.find(p);

    while(index!=-1){
        t.erase(index,p.length());
        index = t.find(p);
    }

    cout<<"final text: "<<t<<endl;

}



