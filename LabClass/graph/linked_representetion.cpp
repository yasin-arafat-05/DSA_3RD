
#include<iostream>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;


class Node{
    public: 
        int data;
        Node *next_link;
        Node *adjecent;
        Node *destenation;

    // for making a node with data value
    Node(int data){
        this->data = data;
        this->adjecent = NULL;
        this->next_link = NULL;
        this->destenation = NULL;
    }
    
    // For adjecent:
    Node(Node *destination){
            this->next_link = NULL;
            this->adjecent = NULL;
            this->destenation = destination;
    }

};

class Graph{
    public:
        Node *start;
        Graph(){
            this->start = NULL;
        }

    //find a node is exist or not:
    Node *findNode(int data){
        Node *temp = start;
        while(temp!=NULL){
            if(temp->data==data){
                return temp;
            }
            temp = temp->next_link;
        }
        return temp;
    }
    
    // insert a node in graph
    void insertNode (int data){
        Node *node1 = findNode(data);
        if(node1 != NULL){
            cout<<"Node is already exist"<<endl;
            return ;
        }
        Node *nodeToInsert = new Node(data);
        nodeToInsert->next_link = start;
        start = nodeToInsert;
    }

    // insert edge
    void insertEdge(int data1,int data2){
        Node *node1 = findNode(data1);
        Node *node2 = findNode(data2);
        if(node1==NULL || node2==Null){
            cout<<"Already Edge Exist"<<endl;
            return ;
        }
    }

    //print the graph:
    void travelElement(){
        Node *temp = start;
        while(temp!=NULL){
            cout<<temp->data;
            Node *temp2 = temp->adjecent;
            while(temp2!=NULL){
                cout<<"-> "<<temp2->destenation->data;
                temp2 = temp2->next_link;
            }
            cout<<','<<endl;
            temp = temp->next_link;
        }
    }
};


int main(){
    yasin
    Graph graph;
    graph.insertNode(5);
    graph.insertNode(6);
    graph.travelElement();

}