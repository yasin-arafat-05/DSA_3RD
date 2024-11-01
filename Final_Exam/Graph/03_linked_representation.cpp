

# include<iostream>
using namespace std;
# define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}


class Node{
    public: 
        int data;
        Node *next;
        Node *adj;
        Node *des;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->adj = NULL;
            this->des = NULL;
        }

        Node(Node *des){
            this->data = 0;
            this->adj = NULL;
            this->next = NULL;
            this->des = des;
        }
};



class Graph{
    public:
        Node *start;
    Graph(){
        start = NULL;
    }

    // ------------------ find node ---------------
    Node *find(int data){
        Node *temp = start;
        while(temp != NULL ){
            if(temp->data == data){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    // ---------------- Insert Node ---------------
    void insertNode(int data){
        if(find(data)){
            cout<<"Node is already exist"<<endl;
            return ;
        }

        if(start==NULL){
            Node *temp = new Node(data);
            start = temp;
        }else{
           Node *temp = new Node(data);
           temp->next = start;
           start = temp;
        }
    }

    // -------------------- Insert Edge ---------------
    void insertEdge(int data1, int data2){
        
        if(find(data1) == NULL || find(data2) == NULL){
            cout<<"Node does not exist"<<endl;
            return ;
        }

        Node *node1 = find(data1);
        Node *node2 = find(data2);

        Node *temp = node1->adj;
        
        while(temp != NULL){
            if(temp->des == node2){
                cout<<"node already exist"<<endl;
                return ;
            }
            temp = temp->next;
        }

        Node *newNode = new Node(node2);
        newNode->next = node1->adj;
        node1->adj = newNode;

    }

    // ----------------- Traversing  ------- 
    void traverse(){
        Node *temp = start;
        while(temp != NULL){
            cout<< temp->data<< " -> ";
            Node *temp2 = temp->adj;
                while(temp2!=NULL){
                    cout<<temp2->des->data;
                    temp2 = temp2->next;
                }
                temp = temp->next;
                cout<<endl;
        }
    }

};


// --------------------- Main Function -----------------------------:

int main(){

    Graph g;
    g.insertNode(5);
    g.insertNode(6);
    g.insertNode(8);
    g.traverse();

    return 0;
}

