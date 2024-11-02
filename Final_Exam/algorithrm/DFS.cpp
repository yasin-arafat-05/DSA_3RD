
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5;
vector<vector<int>> g(N);
vector<bool> Vis(N,false);


void DFS(int vertex){
    Vis[vertex] = true;
    for(int child : g[vertex]){
        if(Vis[child]) continue;
        cout<<"parent: " <<vertex<<" child: "<<child<<endl;
        DFS(child);
    }
}

int main(){
int n,v;
cin>>n>>v;
for(int i=0;i<v;i++){
    int v1,v2;cin>>v1>>v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}

cout<<endl;
cout<<endl;

DFS(1);

}


/*
node edge
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

