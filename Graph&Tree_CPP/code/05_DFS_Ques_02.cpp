
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5;
vector<int> g[N];
bool vis[N];

bool dfs( int vertex,int par ){
    vis[vertex] = true;

    // first we say there is no loop exist
    bool isLoopExist = false;

    for(int child : g[vertex]){
        if (vis[child] && child==par) continue;
        if(vis[child]) return true;

        /*
        আমাদের প্রত্যেক node or vertex check  করবে যে লুপ আছে কিনা তাই যেকোন একটা vertex যদি 
        true return করে তাহলে overall, result তো true হবে । 
        */
        //  |= or is equal to 
        isLoopExist |= dfs(child,vertex);
    }
    return isLoopExist;
}


int main(){
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bool isLoopExist = false;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(dfs(i,1)){
            isLoopExist = true;
            break;
        }
    }

    cout<<isLoopExist<<endl;
}

/*
input:
8 5
1 2
2 3
2 4
3 5
6 7
*/