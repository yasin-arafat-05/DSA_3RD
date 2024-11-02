



/*

    Binary Tree

*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int data){
        this->data = data ;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree{
    public:
        Node *root;
    BinaryTree(){
        root =NULL;
    }
    

    Node *insertInBinaryTree(Node *root){
        int data;
        cout<<"Enter the value for Node: "<<endl;
        cin>>data;
        Node *temp = new Node(data);

        if(data==-1){
            return NULL;
        }

        cout<<"Enter the left value of "<< data <<" : "<<endl;
        temp->left = insertInBinaryTree(temp->left);

        cout<<"Enter the right value of "<< data << " : "<<endl;
        temp->right = insertInBinaryTree(temp->right);

        return temp;
    }


    void inorder(Node *root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(Node *root){
        if(root==NULL){
            return ;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postOrder(Node *root){
        if(root==NULL){
            return ;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

};


int main(){

    BinaryTree bt;
    bt.root = bt.insertInBinaryTree(bt.root);
    cout<<bt.root->data<<endl;

    cout<<"Inorder : "<<endl;
    bt.inorder(bt.root);

    cout<<endl<<"PostOrder: "<<endl;
    bt.postOrder(bt.root);

    cout<<endl<<"PreOrder: "<<endl;
    bt.preorder(bt.root);

}

// 5 12 -1 -1 23 -1 -1 


