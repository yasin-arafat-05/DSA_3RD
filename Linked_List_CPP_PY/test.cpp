#include<iostream>
using namespace std;
void updatefunc(int arr[]){

arr[1] = -12;

}
int main(){
    int arr[5] = {1,2,3,4,5};
    updatefunc(arr);
    for(int i : arr){
        cout<<i<<" ";
    }
}