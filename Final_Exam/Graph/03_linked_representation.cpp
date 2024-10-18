

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
        this->adj  = NULL;
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
    Node *start;


}