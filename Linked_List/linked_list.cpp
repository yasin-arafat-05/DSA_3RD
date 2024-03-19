#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

// Length Of The Linked List 
int lengthOfLinkedList(Node *&head){
    int cnt = 0;
    Node *temp = head;
    while(temp!=nullptr){
        temp = temp->next; cnt++;
    }
    return cnt;
}


// Print All The Element
void traverseAllElement(Node *head){
    Node *temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl;
}

//Insert Element At Head
void insertAtHead(int data,Node *&head,Node *&tail){
    Node *node = new Node(data);
    if(head==nullptr){
        head = node;
        tail = node;
    }else{
        node->next = head;
        head = node;
    }
}

//Insert Element At Tail
void insertAtTail(int data,Node *&head,Node *&tail){
    Node *node = new Node(data);
    if(tail==nullptr){
        head = node;
        tail = node;
    }else{
        tail->next = node;
        tail = node;
    }
}


//Insert Element At Middle:
void insertAtMiddle(int pos,int data,Node *&head,Node *&tail){
    int length = lengthOfLinkedList(head);
    if(pos<=0 || pos>length+1){
        cout<<"Index out of bound error while inserting: "<<data<<" at position: "<<pos<<endl;
        return ;
    }else if(pos==1){
        insertAtHead(data,head,tail);
    }else if(pos==length+1){
        insertAtTail(data,head,tail);
    }else{
        int cnt = 1;
        Node *temp = head;
        while(temp!=nullptr){
            if(cnt==pos-1){
                cout<<cnt<<" "<<pos<<endl;
                break;
            }
            cnt++;
            temp = temp->next;
        }
        Node *node = new Node(data);
        Node *tempStore = temp->next;
        temp->next = node;
        node->next = tempStore;
    }
}



int main(){
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtHead(8,head,tail);
    insertAtHead(7,head,tail);
    insertAtTail(9,head,tail);
    insertAtMiddle(4,123,head,tail);
    traverseAllElement(head);
    cout<<"Length: "<<lengthOfLinkedList(head)<<endl<<"Element of head: "<<head->data<<endl<<"Element of tail: "<<tail->data<<endl;
}
