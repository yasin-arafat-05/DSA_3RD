
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int N = 1e4;
vector<vector<int>> g(N);
int level[N];
vector<bool> vis(N,false);

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(int child : g[cur_v]){
            if(vis[child]) continue;
            q.push(child);
            vis[child] = true;
            level[child] = level[cur_v]+1;
        }
        
    }
}

int main(){

int n;cin>>n;
for(int i=0;i<n;i++){
    int v1,v2;cin>>v1>>v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}

bfs(1);

cout<<endl;
cout<<endl;
for(int i=1;i<=n;i++){
    cout<<i<<" : "<<level[i]<<endl;
}

}

/*

13
1 2 
1 3
1 13
2 5
5 6
5 7
5 8 
8 12 
3 4
4 9
4 10
10 11
9 11

*/