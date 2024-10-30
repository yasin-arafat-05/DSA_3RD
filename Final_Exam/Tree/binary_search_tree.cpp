#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
);

class BST{
public:
    Node *root;
    BST(){
        root = NULL;
    }


    Node *insertToBST(Node *root,int data){

        if(root==NULL){
            Node *newNode = new Node(data);
            return newNode;
        }

        if(root->data > data){
            root->left = insertToBST(root->left,data);
        }
        if(root->data < data){
            root->right  = insertToBST(root->left,data);
        }
        return root
    }

    //--------  take input from user ----------

    void takeInput(Node *root){
        int data;
        cin>>data;
        while(data!=-1){
            root = insertToBST(data);
            cin>>data;
        }
    }

    // --------- inorder travesal --------
    void inOrderTraversal(Node *root){
     if(root == NULL){
            return ;
        }

     inOrderTraversal(root->left);
     cout<<root->data<<endl;
     inOrderTraversal(root->right);
    }

    // --------- preOrder  travesal --------
    void preOrderTraversal(Node *root){
     if(root == NULL){
            return ;
        }
     cout<<root->data<<endl;
     inOrderTraversal(root->left);
     inOrderTraversal(root->right);
    }


    // --------- postOrder  travesal --------
    void postOrderTraversal(Node *root){
     if(root == NULL){
            return ;
        }
     inOrderTraversal(root->left);
     inOrderTraversal(root->right);
     cout<<root->data<<endl;
    }

};


// -------------------- main function ----------------

int main(){

    BST bst;
    bst.takeInput();

}





