#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};



// ----------------- class bst --------------------

class BST {
public:
    Node *root;
    BST() {
        root = NULL;
    }

    Node *insertToBST(Node *root, int data) {
        if (root == NULL) {
            Node *newNode = new Node(data);
            return newNode;
        }

        if (root->data > data) {
            root->left = insertToBST(root->left, data);
        } else if (root->data < data) {
            root->right = insertToBST(root->right, data);
        }
        return root;
    }

    void takeInput() {
        int data;
        cin >> data;
        while (data != -1) {
            root = insertToBST(root, data);
            cin >> data;
        }
    }


// -------------- inorder traversal -----------------
    void inOrderTraversal(Node *root) {
        if (root == NULL) {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

// -------------- pre order traversal -----------------

    void preOrderTraversal(Node *root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

// --------------------- post order traversal --------------------

    void postOrderTraversal(Node *root) {
        if (root == NULL) {
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }


    // ------------------------- Search in binary serach tree -----------------------------

bool searchInBST(Node *root,int data){
    Node *temp = root;

    //------ base case -----
    if(temp==NULL){
        return false;
    }

    if(temp->data == data){
        return true;
    }

    if(temp->data > data){
        return searchInBST(temp->left,data);
    }

    if(temp->data < data){
        return searchInBST(temp->right,data);
    }
    return false;
}

//--------------------------- insert a new node -----------------

Node *insertNewNode(Node *root,int data){
    Node *temp = root;

    if(temp == NULL){
        return new Node(data);
    }

    if(temp->data > data){
        temp->left = insertNewNode(temp->left,data);
    }

    if(temp->data < data){
        temp->right = insertNewNode(temp->right,data);
    }
    
    return root;

}

// ------------------------------ min val and max value ----------

Node *minVal(Node *root){
    Node *temp = root;
    while(temp!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node *maxVal(){
    Node *temp = root;
    while(temp!=NULL){
        temp = temp->right;
    }
    return temp;
}

// ------------------------ Delete Node From BST ----------------------

Node *deleteFromBst(Node *root,int val){

    if(root==NULL){
        return root;
    }

    if(root->data == val){
        // if node have 0 children:
        if(root->left ==NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // if node have left child:
        if(root->left != NULL && root->right == NULL){
            Node *save = root->left;
            delete root;
            return save;
        }

        // if node have right child:
        if(root->left == NULL && root->right != NULL){
            Node *save = root->right;
            delete root;
            return save;
        }

        // if node have two child:
        if(root->left!=NULL && root->right!=NULL){
           int min = minVal(root->left)->data;
           root->data = min;
           root->right = deleteFromBst(root->right,min);

        }

    }else if(root->data > val){
        root->left = deleteFromBst(root->left,val);
    }else if(root->right < val){
        root->right = deleteFromBst(root->right,val);
    }

}


};




// ---------------------- Main function -------------------------

int main() {
    BST bst;
    cout << "Enter elements to insert in BST (-1 to end): ";
    bst.takeInput();

    cout << "\nInOrder Traversal: ";
    bst.inOrderTraversal(bst.root);

    cout << "\nPreOrder Traversal: ";
    bst.preOrderTraversal(bst.root);

    cout << "\nPostOrder Traversal: ";
    bst.postOrderTraversal(bst.root);

    cout<<endl;
    cout<<endl;
    cout<< boolalpha <<bst.searchInBST(bst.root,70);

    cout<<endl<<endl;
    bst.insertNewNode(bst.root,10);
     cout << "\nInOrder Traversal: ";
    bst.inOrderTraversal(bst.root);

    return 0;
}

// 16 18 70 23 -1


