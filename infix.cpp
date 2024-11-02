

#include<iostream>
#include<limits.h>
#include<vector>
const int inf = 1e5;
using namespace std;



int main(){

int e,n;
cout<<"Enter the value of node and edge"<<endl;
cin>>n>>e;
vector<vector<pair<int,int>>> graph(n+1);
cout<<"Enter the value of [u,v,w]: "<<endl;
for(int i=0;i<e;i++){
    int u,v,w;cin>>u>>v>>w;
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
}

// prim's

vector<int> par(n,-1);
vector<int> key(n,inf);
vector<bool> mst(n,false);

// take the input of source:
int source;
cout<<endl<<" give source: "<<endl;
cin>>source;

key[1] = source;

for(int i=1;i<=n;i++){
    
    // find min:
    int min = INT_MAX;
    int u;
    for(int v=1;v<=n;v++){
        if(par[i] && key[v]<min){
            min = key[v];
            u = v;
        }
    }

    // true 
    mst[u]  = true;

    //adjency
    for(auto neighbour : graph[u]){
        int first = neighbour.first; // node
        int secon = neighbour.second; // weight

        if(!par[i] && secon<key[first]){
            key[first] = secon;
            par[first] = u;
        }
    }


    }


    // output: 
    int totalWeight = 0;
    for (int i = 2; i <= n; i++) { 
        cout<< key[i]<<" ";
        totalWeight += key[i];
    }
    cout << endl <<"Total weight of the MST: " << totalWeight << endl;

}

