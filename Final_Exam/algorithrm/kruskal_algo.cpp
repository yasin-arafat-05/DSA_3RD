
#include<iostream>
#include<vector>
using namespace std;
int N = 1e4;
int graph[N][N];

/*
G(V,E)
Time Complexity: O(E log V)
Space Complexity: O(E+V)
*/


int findParent(vector<int> &parent, int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]);
}

void unionSet(int u,int v,vector<int> &parent){
    u = findParent(parent,u);
    v = findParent(parent,v);

}

int main(){
    vector<vector<int>> edge;
    vector<int> parent;
    vector<int> rank;

}


