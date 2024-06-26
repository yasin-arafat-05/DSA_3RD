
/*

so sometime in programming, we know at a compile time, we don't know what is the size of a variable 
or how much memory is required to store the value in a variable at that time 
we guys can use this dynamic memory allocation.

'new' operator is used to allocate the memory dynamically and also 
'delete' operator is used to deallocate the memory.
*/


/*
To properly manage memory and avoid memory leaks, it's important to ensure that all dynamically 
allocated memory is properly freed when it is no longer needed. 
In this case, the removeAtHead and removeAtTail methods should free the memory of the nodes 
they remove. Additionally, the destructor of the LinkedList class should also handle any remaining 
nodes in the list when the LinkedList object is destroyed.

*/



#include<iostream>
using namespace std;
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}


//___________________________________ Class Node ____________________________

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

//___________________________________ Class For Linked List ____________________________

class Linked_List{
    private:
    class HeaderNode{
        public:
        string descp;
        int length; 
        Node *next;

        HeaderNode(const string &descption){
            this->descp = descption;
            this->length = 0;
            this->next = nullptr;
        }
    };
    public:
    int capacity;
    HeaderNode *header;
    Node *tail;

    public:
    Linked_List(int capacity){
        this->header = new HeaderNode("This is header of the linked list.");
        this->capacity = capacity;
        this->tail = nullptr;
    }

    // --------- get the description of the header ----------
    void getHeaderInfo() {
        cout<<"header description: "<< header->descp <<endl;
        cout<<"Length of the Current Linked List:  "<< header->length<<endl;
    }
    // --------- print all element ----------
    void traverseAllElement(){
        Node *temp = header->next;
        while(temp != nullptr){
            cout<< temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // --------- insert element at head ----------
    void insertAtHead(int data){
        if(header->length >= capacity ){
            cout<<"Overflow in the linked list(insert at head)"<<endl;
            return;
        }

        Node *temp = new Node(data);
        Node *storeTemp = header->next;
        header->next = temp;
        temp->next = storeTemp;
        if(tail==nullptr){
            tail = temp;
        }
        header->length++;
    }

    // --------- insert element at tail ----------
    void insertAtTail(int data){
        if(header->length >= capacity){
            cout<<"Overflow in the linked list(inserAtTail)"<<endl;
            return;
        }
        Node *temp = new Node(data);
        if(tail==nullptr){
            header->next = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        header->length++;
    }

    // --------- insert element at any position ----------
    void insertAtAny(int index,int data){

        if(header->length >= capacity){
            cout<<"Overflow in the linked list (inserAtAny)"<<endl;
        }

        if(index<=0 || index > (header->length + 1)){
            cout<<"Array index out of bound error (insertAtMiddle)" <<endl;
        }

        if(index==1){
            insertAtHead(data);
        }else if(index == (header->length+1) ){
            insertAtTail(data);
        }else{
            Node *temp = header->next;
            for(int i =1;i<(index-1);i++){
                temp = temp->next;
            }
            Node *nodeToInsert = new Node(data);
            Node *store = temp->next;
            temp->next = nodeToInsert;
            nodeToInsert->next = store;
            header->length++;
        }
    }
    
    // --------- delete element head ----------
    
    void removeAtHead(){
        if(header->next==nullptr){
            cout<<"Uderflow in the linked list(removeAtHead)"<<endl;
            return;
        }
        Node *temp = header->next->next;
        if(temp==nullptr){
            tail == nullptr;
        }

        Node *removeNode = header->next;
        removeNode->next = nullptr;
        header->next = temp;
        header->length--;
        delete removeNode;
    }

    // --------- delete element tail ----------
    void removeAtTail(){
        if(tail==nullptr){
            cout<<"Uderflow in the linked list(removeAtTail)"<<endl;
            return;
        }
        if(header->next->next != nullptr){
            Node *temp = header->next;
            while(temp->next != tail){
                temp = temp->next;
            }
            Node *noteToDelete = temp->next;
            temp->next = nullptr;
            tail = temp;
            header->length--;
            delete noteToDelete;
        }else{
            Node *nodeTodelete = header->next;
            tail=nullptr;
            header->length--;
            delete nodeTodelete;
        }
        
    }
    // --------- delete element tail ----------

    void removeAtAny(int index){
        if(tail==nullptr){
            cout<<"Underflow in the linked list(deleteAtAny)"<<endl;
        }
        if(index<= 0 || index > header->length ){
            cout<<"Index out of bound error."<<endl;
        }
        if(index==1){
            removeAtHead();
        }else if(index == (header->length)){
            removeAtTail();
        }else{
            Node *temp = header->next;
            for(int i=1;i<(index-1);i++){
                temp = temp->next;
            }
            Node *storeNode = temp->next->next;
            Node *nodeTodelete = temp->next;
            nodeTodelete->next = nullptr;
            temp->next = storeNode;
            header->length--;
            delete nodeTodelete;
        }
    }


    
};

//___________________________________ Main Function ____________________________
int main(){
    yasin
    Linked_List ll(5);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    ll.insertAtAny(2,12);
    ll.insertAtAny(2,13);
    cout<<endl;

    ll.removeAtHead();
    ll.removeAtAny(3);
    ll.removeAtAny(2);
    ll.removeAtAny(1);

    ll.getHeaderInfo();
    ll.traverseAllElement();
    cout<<ll.tail->data<<endl;
    
}

