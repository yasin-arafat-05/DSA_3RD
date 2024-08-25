

#include<iostream>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;

int partition(int arr[],int s,int e){
    // find the right  place of and elemnet(called poviet):
    int poviet = arr[s];
    int cnt = 0;

    for(int i=s+1;i<=e;i++){
        if(poviet >= arr[i]){
            cnt++;
        }
    }
    int povietIndex = s + cnt ;
    swap(arr[povietIndex],arr[s]);


    // handle left and right part:
    int i =s;
    int j = e;

    while(i<povietIndex && j> povietIndex){
        while(arr[i]<poviet){
            i++;
        }
        while(arr[j]>poviet){
            j--;
        }
        if(i<povietIndex && j> povietIndex){
            swap(arr[i++],arr[j--]);
         }
    }

    return povietIndex;
}

void quickSort(int arr[],int s,int e){

    //base case
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){
    int arr[5] = {10,12,7,8,9};
    int size = 5;
    int s=0;
    int e = size-1;
    quickSort(arr,s,e);

    cout<<"sorted array: "<<endl;
    for( int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}