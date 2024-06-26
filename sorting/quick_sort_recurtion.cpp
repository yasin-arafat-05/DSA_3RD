
/*
Code basic in my cpp and dsa khata.
*/


#include<iostream>
using namespace std;
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}


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


void quicksort(int arr[],int s,int e){

    //base case
    if(s>=e){
        return ;
    }

    
    int p = partition(arr,s,e);

    // left part with recurtion:
    quicksort(arr,s,p-1);

    // right part with recurtion:
    quicksort(arr,p+1,e);
}

int main(){
    yasin 
    int arr[5] = {8,6,9,4,5};
    int size = 5;
    int s = 0,e = size-1;

    quicksort(arr,s,e);


    cout<<"sorted array: "<<endl;
    for( int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

}


