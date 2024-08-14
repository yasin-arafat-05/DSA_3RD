#include<iostream>
#include<queue>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
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

Node *insertIntoBST(Node *&root,int data){

    if(root==NULL){
        root =  new Node(data);
        return root;
    }

    if(data< root->data){
        root->left = insertIntoBST(root->left,data);
    }else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

//____________ take input _______________
void takeInput(Node *&root){
    int data;
    cin>>data;
    while(data!=-1){
       root =  insertIntoBST(root,data);
        cin>>data;
    }
}

//______________ lavel order Traversal (same as binary tree) _______________
void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//__________________________ Search In Binary Tree ________________________________

bool searchInBST(Node *root,int data){
    Node *temp = root;
   
    //base case
    if(temp==NULL){
        return false;
    }
    if(temp->data == data){
        return true;
    }

    //logic
    if(temp->data < data){
        return searchInBST(temp->right,data);
    }
    if(temp->data > data ){
        return searchInBST(temp->left,data);
    }
    return false;
}

//_______________________________ Insert New Node In BST _________________________________
Node *insertNewIntoBST(Node *root, int data) {
    Node *temp = root;
    // Base case: If the root is NULL, create a new node and return it
    if (temp == NULL) {
        temp = new Node(data);
        return temp;
    }

    //logic:    
    if (data < temp->data) {
        temp->left = insertNewIntoBST(temp->left, data);
    }
    else {
        temp->right = insertNewIntoBST(temp->right, data);
    }
    return root;
}


//___________________________ Main Function _________________________
// data: 10 8 21 7 27 5 4 3 -1

int main(){
    yasin
    Node *root = NULL;
    cout<<"Enter data for create BST"<<endl;
    takeInput(root);

    /*
    এখানে binary tree এর সব গুলো  algo. apply  করা যাবে  । 
    */
    cout<<"level Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    // search in BST:
    if(searchInBST(root,8)){
        cout<<"Element found."<<endl;
    }else{
        cout<<"Element is not found."<<endl;
    }

    // insert element :
    root = insertNewIntoBST(root,25);
    
    cout<<"level Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

}
