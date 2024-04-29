#include<iostream>
#include<vector>
# define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
const int N = 1e5;
vector<int> graph[N];

void dfsTree(int vertex, int par=0){
    // 4 section fisrt 2 entering(vertex,node) last 2 existing(child,vertex)

    // section 1
    cout<<"Parent: "<<par<<" "<<"vertex: "<<vertex<<endl;

    for(int child:graph[vertex]){
        //section 2
        if(child==par) continue;
        dfsTree(child,vertex);
        //section 3
    }

    //section 4
}
int main(){
    yasin
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfsTree(1);
}


/*
input for a tree:
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10 
10 11
*/
