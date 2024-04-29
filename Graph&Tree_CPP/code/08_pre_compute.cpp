
#include<iostream>
#include<vector>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;

const int N = 1e5;
vector<int> graph[N];
int subTreeSum[N];
int eventCnt[N];

void dfs(int vertex,int par=0){
    
    if(vertex%2==0){
        eventCnt[vertex]++;
    }
    subTreeSum[vertex] = vertex;
    // reminde 4 section:
    for(int child : graph[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subTreeSum[vertex] += subTreeSum[child];
        eventCnt[vertex] += eventCnt[child];
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

    cout<<" Sub Tree + event count:  "<<endl;
    for(int i=1;i<=n;i++){
        cout<< subTreeSum[i] << " " << eventCnt[i]<< endl;
    }
    cout<<endl;

}