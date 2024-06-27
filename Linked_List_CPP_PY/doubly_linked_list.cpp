#include<iostream>
using namespace std;
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
//___________________________ Node _______________________________
class Node{
    private:
        int data;
        Node *prev;
        Node *next;
    public:
        Node(int data){
            this->data = data;
            prev = nullptr;
            next = nullptr;
        }

};

//_____________________________--__ Linked List Class ______________________________________
class Linked_List{
    public:
        int capacity;
        int current;
    Linked_List(int capacity){
        this->capacity = capacity;
        current = 0;
    }

    //_____________ Current Length of the Linked List _______________
    void getLength(){
        cout<<"length: "<<current<<endl;
    }
    
};
//___________________________ Main Function _____________________________
int main(){
    yasin
    Linked_List ll(5);

    cout<<ll.capacity<<endl;
    ll.getLength();
}