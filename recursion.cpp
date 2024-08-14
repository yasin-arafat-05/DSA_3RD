
#include<iostream>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;

void cnt(int n){
    
    //base case 
    if(n==0){
        return ;
    }
    cnt(n-1);
    cout<<n<<endl;
}

int main(){
    yasin
    cnt(10);
}