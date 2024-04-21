
/*
    show all the connected component in a graph:
*/

#include<iostream>
#include<vector>

using namespace std;

const int N = 1e5;
vector<int> g[N];
vector<vector<int>> connceted_component;
vector<int> temp;
bool vis[N];


void dfs(int vertex){
    vis[vertex] = true;
    temp.push_back(vertex);
    for(int child : g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}

int main(){
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int ct = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        temp.clear();
        dfs(i);
        connceted_component.push_back(temp);
        ct++;
    }
    cout<<connceted_component.size()<<endl;
    for(auto i : connceted_component){
        for( auto k : i){
            cout<<k<<" ";
        }
        cout<<endl;
    }

}