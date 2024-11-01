


#include<iostream>
using namespace std;
int main(){
    int n =10;
    int arr[10] = {1,2,3,45,67,-4,8,10,20,12};

    int searchElement = -12;

    bool ans = false;

    for(int i=0;i<n;i++){
        if(searchElement == arr[i]){
            ans = true;
        }
    }

    cout<<boolalpha<<"Element exist or not? : " <<ans<<endl;
}


