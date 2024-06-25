
#include<iostream>
using namespace std;
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

//______________________________________ Class for Node _____________________________________

class Node{

    // access modifier + ( data member / property )
    public:
    int data;
    Node *next;

    // Constructor
    Node(int data){
        // this->data (data member) = data (formal parameter)
        this->data = data;
        this->next = nullptr;
    }
};


//__________________________________ Class for LInked List ____________________________________

class Linked_List{
    // ________________ access modifier + (class memeber):
    // head is node where our first node of linked will be there.
    // tail, is the node which consist our last node.
    // avail for garbase collection:
    public:
    Node *head;
    Node *tail;
    Linked_List *avail;
    int capacity;
    int currentsize;
    //_______ constructor:

    Linked_List(int capacity){
        head = nullptr;
        tail = nullptr;
        currentsize = 0;
        this->capacity = capacity;

        // initilize the avail list:
        for(int i=0;i<capacity;i++){
            Node *node = new Node(-1);
            node->next = avail->head;
            avail->head = node;
            if(avail->tail==nullptr){
                avail->tail=node;
            }
        }
    }

    // _______ garbase collection:
    private:
    Node *getNode(int data){
        // while creating a new node:
        if(avail->head != nullptr){
            Node *temp  = avail->head;
            avail->head = avail->head->next;
            if(avail->head==nullptr){
                avail->tail = nullptr;
            }
            temp->data = data;
            temp->next = nullptr;
            return temp;
        }
        return new Node(data); // error handale using currentSize:
    }

    // delete node 
    void recycleNode(Node *temp){
        temp->next = avail->head;
        avail->head = temp;
        if(avail->tail==nullptr){
            avail->head=temp;
        }
    }

    //_______ length of the linked list:
    public:
    int length(){
        return currentsize;
    }

    //________ print or traverse all the element:
    void traverseAllElement(){
        /*
        When you write Node temp; 
        You are attempting to create an instance of Node on the stack. 
        This means that the constructor for Node needs to be called to initialize the instance.
        Because the constructor is private, you cannot directly create instances of Node outside the class.

        When you write Node *temp;
        you are declaring a pointer to a Node object but not actually creating a Node instance yet.
        This pointer can be assigned the address of an existing Node instance or set to nullptr.
        */
        Node *temp = head;
        while (temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // ________________ Insert Element At Head:
    void insertAtHead(int data){
        if(currentsize>=capacity){
            cout<<"Overflow in the linked list."<<endl;
            return; // return if condition is true then it's will not run the code under if statemaent.
        }

        Node *temp = getNode(data); //creating new node

        if (head==nullptr){
            head = temp;
            tail = temp;
        }else{
        temp->next = head;
        head = temp;
        }
        currentsize++;
    }

    // ________________ Insert Element At Tail:
    void insertAtTail(int data){
        if(currentsize>=capacity){
            cout<<"Overflow in the linked list(Insert_At_Tail)."<<endl;
            return ;
        }
        Node *temp = getNode(data);
        if(head==nullptr){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        currentsize++;
    }

    // ________________ Insert Element At Middle:
    void insertAtMiddle(int index,int data){
        if(currentsize >= capacity){
            cout<<"Overflow in the linked list.(insertAtMiddle)"<<endl;
            return;
        }
        if(index<=0 || index > currentsize+1){
            cout<<"Array index out of bound error."<<endl;
        }
        if(index==1){
            insertAtHead(data);
        }else if(index == (currentsize+1)){
            insertAtTail(data);
        }else{
            Node *temp = head;
            for(int i=1;i<(index-1);i++){
                temp = temp->next;
            }
            Node *insertNode = getNode(data);
            Node *tempStore = temp->next;
            temp->next = insertNode;
            insertNode->next = tempStore;
            currentsize++;
        }

    }

    // ________________ Delete Element From Head:

    void removeAtHead(){
        if(head==nullptr){
            cout<<"Underflow in the linked list.(removeAtHead)"<<endl;
        }
        Node *temp = head;
        head = head->next;
        if(head==nullptr) tail=nullptr;
        recycleNode(temp);
        currentsize--;
    }

    // ________________ Delete Element From tail:
    void removeAtTail(){
        if(tail==nullptr){
            cout<<"Underflow in the linked list(removeAtTail)."<<endl;
        }
        if(head == tail){
            recycleNode(head);
            head = nullptr;
            tail = nullptr;
        }else{
            Node *temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            recycleNode(tail);
            tail = temp;
            tail->next = nullptr;
        }
        currentsize--;
    }

    // ________________ Delete Element From At any position:

    void removeAtPosition(int index){
        if(index<=0 || index > currentsize ){
            cout<<"Index out of bound error.(removeAtPosition)"<<endl;
            return;
        }
        if(index==1){
            removeAtHead();
        }else if(index==currentsize){
            removeAtTail();
        }else{
            Node *temp = head;
            for(int i=1;i<(index-1);i++){
                temp = temp->next;
            }
            Node *removeNode = temp->next;
            temp->next = removeNode->next;
            removeNode->next = nullptr;
            recycleNode(removeNode);
            currentsize--;
        }
    }

};


//______________________________________ Main Function _____________________________________
int main(){
    yasin 
    int capacity = 5;
    Linked_List list(capacity);

    //insertion:

    list.insertAtHead(3);
    list.insertAtHead(1);
    cout<<list.currentsize<<endl;
    list.insertAtMiddle(3,12);
    list.insertAtMiddle(3,13);
    list.insertAtMiddle(3,14);
    
    list.insertAtMiddle(3,100); // give us the overflow error:

    cout<<"head: "<<list.head->data<<endl;
    cout<<"tail: "<<list.tail->data<<endl;
    list.traverseAllElement();

    cout<<endl;
    cout<<"Deletion part"<<endl;
    cout<<endl;

    // deletion:
    list.removeAtHead();
    list.removeAtTail();

    list.removeAtPosition(2);

    list.removeAtPosition(1);

    list.removeAtHead();

    list.traverseAllElement();
    cout<< "current size: " <<list.currentsize<<endl;
    

}