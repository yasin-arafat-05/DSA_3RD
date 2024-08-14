
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

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

void insertFromArray(vector<int> &nodes, int &index,node *&root){
    if(index>=nodes.size() || nodes[index]==-1){
        index++;
        return ;
    }
    root  = new node(nodes[index++]);
    insertFromArray(nodes,index,root->left);
    insertFromArray(nodes,index,root->right);
}

//_____________________ Level order Traversal __________________________
void levelOrderTraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ){
        node *temp = q.front();
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

//_____________________ Main Function ____________________

int main(){
    yasin
    node *root = NULL;
    vector<int>  nodes = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    int index = 0;
    insertFromArray(nodes,index,root);
    printf("done /n done");
    levelOrderTraversal(root);
    return 0;
}