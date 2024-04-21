
# include<iostream>
#include<vector>
using namespace std;

#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

const int N = 1e5;
vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    vis[vertex] = true;
    for(int child: g[vertex]){
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

    // how many time dfs called:
    int ct = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        ct++;
    }

    cout<<"nuber of connected component: "<<ct<<endl;

}