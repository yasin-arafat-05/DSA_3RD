
#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


class LinkedList{
public:
    Node *head;
    Node *tail;
    LinkedList *avail;
    int currentSize;
    int size;

LinkedList(int n){
    this->size = n;
    this->head = NULL;
    this->tail = NULL;
    this->currentSize  = 0 ;

    for(int i=0;i<n;i++){
        Node *newNode = new Node(-1);
        newNode->next = avail->head;
        avail->head = newNode;
        if(avail->tail==NULL){
            avail->tail = newNode;
        }
    }
}


// --------------- creating a new node -------------------
Node *getNode(int data){
  
    if(avail->head != NULL){
        Node  *temp = avail->head;
        avail->head = avail->head->next;
        if(avail->head == NULL){
            avail->tail = NULL;
        }
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
    return new Node(data);
}

void recycleNode(Node *node){
    node->next = avail->head;
    avail->head = node;
    if(avail->tail==NULL){
        avail->head = tail;
    }
}

//---------------insert element at head----------------------:
void insetAtHead(int data){
    if(currentSize>=size){
        cout<<"Overflow in the linked list insert at head"<<endl;
        return ;
    }
    Node *temp = getNode(data);
    if(head==NULL){
        head = temp;
        tail = temp;
    }else{
        temp->next = head;
        head = temp;
    }
    currentSize++;
}

//---------------- inset element at tail------------------:
void insertAttail(int data){
    if(currentSize>=size){
        cout<<"Overflow in the lined list insert at tail"<<endl;
        return ;
    }
    Node *newNode = getNode(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
        tail->next = newNode;
        tail = newNode;
        currentSize++;
}

//-------------------- insert element at any pos --------------------:
// ________________ Insert Element At Middle:
    void insertAtMiddle(int index,int data){
        if(currentSize > size){
            cout<<"Overflow in the linked list.(insertAtMiddle)"<<endl;
            return;
        }
        if(index<=0 || index > currentSize+1){
            cout<<"Array index out of bound error."<<endl;
        }
        if(index==1){
            insetAtHead(data);
        }else if(index == (currentSize+1)){
            insertAttail(data);
        }else{
            Node *temp = head;
            for(int i=1;i<(index-1);i++){
                temp = temp->next;
            }
            Node *insertNode = getNode(data);
            Node *tempStore = temp->next;
            temp->next = insertNode;
            insertNode->next = tempStore;
            currentSize++;
        }

    }

// ------------------- delete element from head ------------
void deleteFromHead(){

    if(head==NULL){
        cout<<"Underflow: in delete from head"<<endl;
    }

    Node *temp = head;
    head = head->next;

    if(head==NULL){
        tail = NULL;
    }

    recycleNode(temp);
    currentSize--;
}

// ---------------------- delete element from tail ------------------------

void deleteFromTail(){
    if(currentSize<=0){
        cout<<"Under flow in deleteFrom tail"<<endl;
        return ;
    }

    if(head==tail){
        recycleNode(head);
        head = NULL;
        tail = NULL;
    }else{
        Node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
         recycleNode(tail);
         tail = temp;
        tail->next = NULL;
    }
    currentSize--;
}

// ------------- delete element from any node ----------------------:
void deleteAtPos(int pos){
    if(pos<=0 || pos> currentSize+1){
        cout<<"invalid position"<<endl;
        return ;
    }
    if(pos==1){
        deleteFromHead();
    }else if(pos == currentSize){
        deleteFromTail();
    }else{
        Node *temp = head;
        for(int i=1;i<=(pos-1);i++){
            temp = temp->next;
        }
        Node *saveNode = temp->next->next;
        recycleNode(temp->next);
        temp->next = saveNode;
        currentSize--;
    }
}

//-----------------------print element-------------------------:
void traverseElement(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        }
    }
};


// --------------------- Main function ---------------:
int main(){
    LinkedList ll(5);

    ll.insetAtHead(5);
    ll.insertAttail(8);
    ll.insertAttail(10);

    ll.insertAtMiddle(4,100);
    ll.insertAtMiddle(5,123);
    ll.traverseElement();
    cout<<endl;
    cout<<"head: "<<ll.head->data<<endl;
    cout<<"tail: "<<ll.tail->data<<endl;

    cout<<endl;
    cout<<endl;

    ll.deleteFromHead();
    ll.traverseElement();
    cout<<endl;
    cout<<"head: "<<ll.head->data<<endl;
    cout<<"tail: "<<ll.tail->data<<endl;


    cout<<endl;
    cout<<endl;

    ll.deleteFromTail();
    ll.traverseElement();
    cout<<endl;
    cout<<"head: "<<ll.head->data<<endl;
    cout<<"tail: "<<ll.tail->data<<endl;


    cout<<endl;
    cout<<endl;

    ll.deleteAtPos(3);
    ll.traverseElement();
    cout<<endl;
    cout<<"head: "<<ll.head->data<<endl;
    cout<<"tail: "<<ll.tail->data<<endl;


}



