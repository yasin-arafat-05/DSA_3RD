
#include<iostream>
#include<queue>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;

//___________________ Node ____________________
/*

            [1]  
           /   \
        [NULL]     [NULL]
       
*/
class node{
    public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

//______________creating binary tree___________
/*

-> root বানানোর পর আমরা বাকি binary tree টা বানাতে পারবো । 
তাই আগে root বানানোর পর এতে child add করবো । 

-> -1 যখন user input  দিবে সেইটাকে null হিসেবে count করবো । 

-> first insert data in left node then right node

*/
node *createTree(node *root){
    cout<<"Enter a data for node: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data==-1){
        return NULL;
    }

    cout<<" Enter the data for inserting in left node of : "<<data<<endl;
    root->left = createTree(root->left);
    
    cout<<" Enter the data for inserting in right node of : "<<data<<endl;
    root->right = createTree(root->right);
    return root;
}

// _______________ Lavel order -> traversal __________________
void levelOrderTraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); // Null means level one done

    while( (!q.empty()) ){

        node *temp = q.front();
        q.pop();

        if(temp==NULL){ // level done press enter
            cout<<endl;
            if((!q.empty())){ // still queue has some child then 
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

//_________________ In-order -> traversal___________________
void inorderTraversal(node *root){
    if(root==NULL){
        return ;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

//_________________ Pre-order -> traversal___________________
void prerderTraversal(node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    prerderTraversal(root->left);
    prerderTraversal(root->right);
}

//_________________ Post-order -> traversal___________________
void postrderTraversal(node *root){
    if(root==NULL){
        return ;
    }
    postrderTraversal(root->left);
    postrderTraversal(root->right);
    cout<<root->data<<" ";
}




//______________ Main Function ________________

// data: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

int main(){
    yasin
    node *root = NULL;
    // creating binary tree
    /*
    recursive call কীভাবে হচ্ছে সেইটা খাতায় আকো । 
    */
    root = createTree(root); 
    
    cout<<endl;
    cout<<endl;

    //_________ traversal __________________

    // level order traversal 
    cout<<"level_order "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    // in_order, pre_order, post_order.
    cout<<"in-order: "<<endl;
    inorderTraversal(root);
    cout<<endl; 

    cout<<"in-order: "<<endl;
    prerderTraversal(root);
    cout<<endl; 
    

    cout<<"post-order: "<<endl;
    postrderTraversal(root);
    cout<<endl; 
    
}



