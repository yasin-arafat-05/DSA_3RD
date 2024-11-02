

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
const int inf = 1e5;


int main(){

    // input and other's 
    int node,edge;
    cout<<"Enter the value of node and edge"<<endl;
    cin>>node>>edge;
    vector<vector<pair<int,int>>> graph(node+1);

    cout<<"Enter edages: [u,v,w]"<<endl;
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }   

    // for the algo:
    vector<int> parent(node+1,-1);
    vector<int> key(node+1,inf);
    vector<bool> mst(node+1,false);

    // --- start the algo ------
    key[1] = 0;

    

    for(int i=1;i<=node;i++){
        
        //--step 01: find mini node
        int mini = INT_MAX;
        int u;
        for(int v=1;v<=node;v++){
            // mst[v] == false
            if(!mst[v] && key[v]<mini){
                u = v;
                mini = key[v];
                cout<<"core dumb: "<<i<<endl;
            }
        }

        //--step 02: mark mini as true
        mst[u] = true;

        //---step 03: check adjency: 
        for(auto it: graph[u]){
            int v = it.first;
            int w = it.second;
            if(!key[u] && w<key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }


    //---- output: 

    int totalWeight = 0;
    cout << "Edges in the MST:\n";
    for (int i = 2; i <= node; i++) { // Start from 2, as 1 is the starting node
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
        totalWeight += key[i];
    }
    cout << "Total weight of the MST: " << totalWeight << endl;




}



/*

Enter the number of nodes and edges: 4 5
Enter the edges (u v w):
1 2 10
1 3 6
1 4 5
2 4 15
3 4 4


*/

