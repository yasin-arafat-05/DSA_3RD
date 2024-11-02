
#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node *next;

    // conustuctor:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


// linked list:

class LinkedList{
    public:
    Node *head;
    Node *tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
    }


  // --------------- Insert value at head ---------------------------

  void insertAtHead(int data){
    Node *newNode = new Node(data);

    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
  }

  // ------------------ insert at tail -------------------
    void insertAtTail(int data){
        Node *temp = new Node(data);
        if(head==NULL){
            head = temp;
            tail = temp;
            return;
        }

        tail->next = temp;
        tail = temp;

    } 

    // --------------------- insert at middle -------------------

    void insertAtAny(int pos,int data){
        Node *newNode = new Node(data);

        if(pos==1){
            insertAtHead(data);
            return;
        }

        Node *temp = head;
        for(int i=1;i<(pos-1);i++){
            temp = temp->next;
        }

        // tail 
        if(temp->next==NULL){
            insertAtTail(data);
            return;
        }

        Node *save = temp->next;
        temp->next = newNode;
        newNode->next = save;

    }
    

 // ----------------- detele from head -----
    void deleteFromHead(){
        if(head==NULL){
            cout<<"No element in the linked list."<<endl;
            return;
        }

        head = head->next;
    }

 // ----------------- detele from tail -----
    void deleteFromTail(){
        if(head==NULL){
            cout<<"No element in the linked list."<<endl;
            return;
        }

        Node *temp = head;
        while(temp->next != tail){
            temp=temp->next;
        }
        temp->next = NULL;
        tail = temp;
        
    }


    // --------------------- delete from any  -------------------

    void deleteAtAny(int pos){

        if(pos==1){
            deleteFromHead();
            return;
        }

        Node *temp = head;
        for(int i=1;i<(pos-1);i++){
            temp = temp->next;
        }

        // tail 
        if(temp->next->next==NULL){
            deleteFromTail();
            return;
        }
        
        Node *save = temp->next->next;
        temp->next->next = NULL;
        temp->next = save;
        
    }


  // traversal
  void traversal(){
    Node *temp = head;
    while (temp!=NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    
  }

};

int main(){
   LinkedList ll;
   ll.insertAtHead(5);
   ll.insertAtHead(6);
   ll.insertAtHead(12);
   ll.insertAtHead(15);
   cout<<endl<<endl;

   ll.insertAtTail(7);


   ll.insertAtAny(4,100);

   ll.traversal();

   cout<<endl<<"Head: "<<ll.head->data<<endl;
   cout<<"Tail: "<<ll.tail->data<<endl;


   cout<<endl<<endl;
   cout<<"delete element from head : "<<endl;
   ll.deleteFromHead();
   ll.traversal();
   cout<<endl<<"Head: "<<ll.head->data<<endl;
   cout<<"Tail: "<<ll.tail->data<<endl;

   cout<<endl<<endl;
   cout<<"delete element from tail : "<<endl;
   ll.deleteFromTail();
   ll.traversal();
   cout<<endl<<"Head: "<<ll.head->data<<endl;
   cout<<"Tail: "<<ll.tail->data<<endl;


   cout<<endl<<endl;
   cout<<"delete element from any : "<<endl;
   ll.deleteAtAny(4);
   ll.traversal();
   cout<<endl<<"Head: "<<ll.head->data<<endl;
   cout<<"Tail: "<<ll.tail->data<<endl;
}

