
#include<iostream>
#include<vector>
#define yasin{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
int depth[N];

void dfs(int vertex,int par=0){
    for(int child: graph[vertex]){
        if(child==par) continue;
        depth[child]=depth[vertex] + 1;
        dfs(child,vertex);
    }
}

int main(){
    yasin
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);
    int mx_depth = -1;
    int mx_depth_node;
    for(int i=0;i<=n;i++){
        if(mx_depth<depth[i]){
            mx_depth = depth[i];
            mx_depth_node = i;
        }
        depth[i] = 0;
    }
    
    dfs(mx_depth_node);

    for(int i=0;i<=n;i++){
        if(mx_depth<depth[i]){
            mx_depth = depth[i];
        }
    }

    cout<<mx_depth<<endl;


}