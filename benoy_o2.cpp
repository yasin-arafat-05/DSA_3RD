

/*

    Binary Search Tree

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


// --------- BST ------------

class BST{
    public:
        Node *root;
    BST(){
        root = NULL;
    }

    Node *insertInBST(Node *root,int data){
        
        if(root==NULL){
            Node *newNode = new Node(data);
            return newNode;
        }

        if(root->data > data){
            root->left = insertInBST(root->left,data);
        }else if(root->data < data){
            root->right = insertInBST(root->right,data);
        }
        
        return root;
    }

    void input(){
        int data;
        cout<<" Enter the root Node: "<<endl;
        cin>>data;

        while(data != -1){
            root = insertInBST(root,data);
            cin>>data;
        }
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

    BST bst;
    bst.input();

    cout<<"inorder: "<<endl;
    bst.inorder(bst.root);

}

