
/*
Code basic in my cpp and dsa khata.
*/


#include<iostream>
using namespace std;
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}


// ____________________ This method i learn from love babbar course ____________________________
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

//___________________________ This method inspried by our dsa book _________________________
int partitionDsaBook(int *arr, int beg, int end) {
    int left = beg, right = end;
    int loc = beg;

    while (true) {
        // Move the right pointer towards the left until an element smaller than or equal to the pivot is found
        while (arr[loc] <= arr[right] && loc != right) {
            right--;
        }
        if (loc == right) return loc;
        
        if (arr[loc] > arr[right]) {
            swap(arr[loc], arr[right]);
            loc = right;
        }

        // Move the left pointer towards the right until an element greater than or equal to the pivot is found
        while (arr[loc] >= arr[left] && loc != left) {
            left++;
        }
        if (loc == left) return loc;
        if (arr[loc] < arr[left]) {
            swap(arr[loc], arr[left]);
            loc = left;
        }
    }
}



void quicksort(int arr[],int s,int e){

    //base case
    if(s>=e){
        return ;
    }

    int p = partitionDsaBook(arr,s,e);

    // left part with recurtion:
    quicksort(arr,s,p-1);

    // right part with recurtion:
    quicksort(arr,p+1,e);
}

int main(){
    yasin 
    int arr[5] = {13,15,2,3,5};
    int size = 5;
    int s = 0,e = size-1;

    quicksort(arr,s,e);


    cout<<"sorted array: "<<endl;
    for( int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

}


