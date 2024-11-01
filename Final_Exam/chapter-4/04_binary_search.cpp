
#include<iostream>
using namespace std;

bool binarySearch(int arr[],int n,int key){
    int s = 0;
    int e = n-1;
    
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]<key){
            s = mid +1;
        }else if(arr[mid]>key){
            e = mid - 1;
        }else if(arr[mid] == key ){
            return true;
        }
    }
    
    return false;
}


int main(){
    int n = 5;
    int arr[5] = {1,2,3,4,5};

    if(binarySearch(arr,n,4)){
        cout<<"Element Found"<<endl;
    }else{
        cout<<"Element Not Found"<<endl;
    }

}


