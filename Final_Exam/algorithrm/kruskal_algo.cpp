#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// step: 01, Function to create a set
void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0; // Initialize rank
    }
}

// step: 02 Function to find the parent of a node with path compression
int findParent(vector<int> &parent, int node){
    if(parent[node] != node){
        parent[node] = findParent(parent, parent[node]); // Path compression
    }
    return parent[node];
}

// step:03 Function to union two sets
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);
    if(u != v){
        if(rank[u] < rank[v]){
            parent[u] = v;
        } else if(rank[v] < rank[u]){
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main(){
    int n = 4; // Number of nodes
    vector<vector<int>> edge = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Sort edges based on weight
    sort(edge.begin(), edge.end(), [](const vector<int>& a, const vector<int>& b) {
        // with respect to 2 or weight
        return a[2] < b[2]; 
    });

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n); // Initialize disjoint sets

    int minWeight = 0;
    for(int i=0; i<edge.size(); i++){
        int u = edge[i][0]; // First vertex
        int v = edge[i][1]; // Second vertex
        int w = edge[i][2]; // Weight

        if(findParent(parent, u) != findParent(parent, v)){
            minWeight += w; // Add weight to total
            unionSet(u, v, parent, rank); // Union the sets
        }
    }

    cout << "Minimum Spanning Tree weight: " << minWeight << endl;

    return 0;
}


