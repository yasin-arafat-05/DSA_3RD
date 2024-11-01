

#include<iostream>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
const int N = 1e5;
int arr[N];

int main(){
    int n;

    //_________________ take input for array __________________________

    cout<<"Enter the value size of an array: "<<endl;
    cin>>n;

    cout<<"Enter the value of all the element of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //_________________ traversing of a linear array_________________________
    cout<< "Traversing of linear array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //_________________ inserting elelment ________________________________
    int pos,ele;
    cout<<"Insert Element: "<<endl;
    cout<<"position: ";
    cin>>pos;
    cout<<"element: ";
    cin>>ele;
    int j;
    for(j=n;j>=pos;j--){
        arr[j] = arr[j-1];
    }
    arr[pos-1] = ele;
    n++;

    cout<< "Traversing after inserting element : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //_________________ delete elelment ________________________________
    int pos1,ele1;
    cout<<"Delete Element: "<<endl;
    cin>>pos1;
   
    int k;
    for(k=pos1-1;k<n;k++){
        arr[k] = arr[k+1];
    }
    n--;

    cout<< "Traversing after deleting element : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}



