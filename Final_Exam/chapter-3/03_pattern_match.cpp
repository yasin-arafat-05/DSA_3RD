

#include<iostream>
using namespace std;
int main(){

    string t,p;

    cout<<"Enter a text: "<<endl;
    getline(cin,t);

    
    cout<<"Enter a pattern: "<<endl;
    getline(cin,p);

    int textSize = t.size();
    int patternSize = p.size();

    bool ans = false;

    for(int i=1;i<=(textSize-patternSize+1);i++){
        int k;
        for(k=1;i<patternSize;k++){
            if(p[k-1] != t[i+k-2]) break;
        }

        if(k== (patternSize)){
                ans = true;
                break;
        }
    }

    cout<<boolalpha<<ans<<endl;

}