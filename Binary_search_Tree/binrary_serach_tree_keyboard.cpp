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

//____________________________ Find Minimum amd Maximum value _____________________

Node *minVal(Node *root){
    Node *temp = root;
    while(temp->left!=NULL){
        temp  = temp->left;
    }
    return temp;
}

Node *maxVal(Node *root){
    Node *temp = root;
    while(temp->right!=NULL){
        temp  = temp->right;
    }
    return temp;
}

// Delete from BST:

Node *deleteFromBST(Node *root, int val){

    //base case 
    if(root==NULL){
        return root;
    }

    if(root->data==val){
        // 0 child 
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 child
            // left child 
            if(root->left!=NULL && root->right==NULL){
                Node  *temp = root->left;
                delete root;
                return temp;
            }
            // right child
            if(root->right!=NULL && root->left==NULL){
                Node *temp = root->right;
                delete root;
                return temp;
            }
        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int min = minVal(root->right)->data;
            root->data = min;
            // now delete the minimum value from the root->right
            root->right = deleteFromBST(root->right,min);
        }

    }else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
    }else{
        root->right = deleteFromBST(root->right,val);
    }

    /* 
    Rrecursion diye call return korar time e suru te jei root diye chilam akdom 
    shes e sei root tai pabo . tai no tension just play with reursion.
    */
    return root;
}

//___________________________ Main Function _________________________
// data: 10 8 21 7 27 5 4 3 -1
// data(delete_Node): 100 50 25 70 60 110 120 115 -1

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
   // root = insertNewIntoBST(root,25);
    cout<<"minvalue: "<<minVal(root)->data<<" "<<endl;
    cout<<"maxvalue: "<<maxVal(root)->data<<" "<<endl;

    root = deleteFromBST(root,50);

    cout<<"level Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

}
