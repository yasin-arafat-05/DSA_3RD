
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
int parent[N];

void dfs(int vertex,int par = -1){
    parent[vertex] = par;
    for(int child:graph[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
    }
}

vector<int> path(int v){
    vector<int> ans{0,0};
    while(v!=-1){
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

   
    dfs(1);
   
    cout<<endl;
    
    //________test input_________
    int x,y;
    x = 6;
    y = 7;


    vector<int> path_x = path(x);
    vector<int> path_y = path(y);


    int min_length = min(path_x.size(),path_y.size());

    int ans;
    for(int i=0;i<=min_length;i++){
        if(path_x[i] == path_y[i]){
            ans = path_x[i];
        }else break;
    }
    cout<<ans<<endl;
}


