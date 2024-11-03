
#include<iostream>
using namespace std;


void merge(int *arr,int s,int e){

    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    //___________ copy ___________
    int k = s;
    for(int i=0;i<len1;i++){
        arr1[i] = arr[k++];
    }

    for(int i=0;i<len2;i++){
        arr2[i] = arr[k++];
    }

    //__________ merge____________
    int index1 = 0;
    int index2 = 0;
    k = s;
    while(index1<len1 && index2<len2){
        if(arr1[index1]<arr2[index2]){
            arr[k++] = arr1[index1++];
        }else{
            arr[k++] = arr2[index2++];
        }
    }

    while(index1<len1){
        arr[k++] = arr1[index1++];
    }

    while(index2<len2){
        arr[k++] = arr2[index2++];
    }

}


void mergeSort(int *arr,int s, int e){

    if(s>=e){
        return;
    }

    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

// main function 

int main(){

    int arr[5] = {45,12,78,90,1};

    mergeSort(arr,0,4);

    cout<<endl;
    cout<<endl;

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}



