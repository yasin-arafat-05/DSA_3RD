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
};

class Tree{
 public:
 Node *root;

 //---------------- constructor of the tree -----------
    Tree(){
       root = NULL;
    }

 //___________________ insert into tree ---------------
 Node *insertToTree(Node *root){
        int data;
        cout<<"Enter a data Node: "<<endl;
        cin>>data;
        root = new Node(data);

     if (data == -1){
        return NULL;
     }

     // if root is not empty
     cout<<"insert data to the left of: " << data <<endl;
     root->left = insertToTree(root->left);
     
     cout<<"insert data to the right of: "<< data <<endl;
     root->right = insertToTree(root->right);

     return root;
  }

 // ------------------------ inorder traversal ---------------------
 
 void inorderTraversal(Node *root){
   if (root == NULL){
      return ;
   }
   inorderTraversal(root->left);
   cout<<root->data<<" ";
   inorderTraversal(root->right);
 }
};


// ------------------- Main Function ----------------------


int main(){
    Tree tree;
    tree.root = tree.insertToTree(tree.root);
    tree.inorderTraversal(tree.root);
}









