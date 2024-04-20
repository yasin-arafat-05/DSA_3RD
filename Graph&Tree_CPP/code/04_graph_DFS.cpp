
#include<iostream>
#include<vector>

using namespace std;

#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N = 1e5;
vector<int> graph[N];

// visited graph
bool vis[N];



void dfs(int vertex){
    //___Take action on vertex after entering the vertex___
    /*
     While we are visiting a vertex check it is visited or not:
    */
    cout<<vertex<<endl;
    vis[vertex] = true;

  for(int child : graph[vertex]){

    cout<<"par: "<<vertex<<" " <<"child: "<<child<<endl;

    if(vis[child]) continue;
    //_____Take action on child before(calling dfs) entering the child node ________

    dfs(child);
    //_____Take action on child after(calling dfs) existing the child node ________

  }
    //_____Taking action over vertex before existing the child node ________

}

int main(){
    yasin 
    int n,m;cin>>n>>m;

    //____ input the graph in adjacency list _____
    for(int i=0;i<m;i++){
        int v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);

}

/*
input:
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/