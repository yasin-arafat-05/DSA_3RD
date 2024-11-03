

#include<iostream>
#include<vector>
#include<set>

using namespace std;
const int inf = 1e7;

int main(){

    int n,e;cout<<"Enter the value of Edge: "<<endl;
    cin>>n>>e;

    vector<vector<pair<int,int>>> graph(n+1);
    vector<int> dist(n+1,inf);

    cout<<"Enter the value in the format of [u,v,w]: "<<endl;
    for(int i=0;i<e;i++){
        int u,v,w;cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    cout<<"Enter the source Node: "<<endl;
    int source;
    cin>>source;
    dist[source] = 0;


    set<pair<int,int>> st;

    st.insert({0,source}); // dist,node

    while (!st.empty()){
        auto top = *(st.begin());
        int dis = top.first;
        int nodeValue = top.second;
        st.erase(st.begin());

        for(auto neighbor :  graph[nodeValue]){
            int adjNode = neighbor.first;
            int adjWeith = neighbor.second;
            if((dis+adjWeith) < dist[adjNode]){
                // remove the old pair
                if(dist[adjNode] != inf){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = dis+adjWeith;
                st.insert({dist[adjNode],adjNode});
            }

        }
    }


    cout<<"shortest distance from source: "<<source<<endl: 
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}

/*

4 5

0 1 5
0 2 8
1 2 9
1 3 2
3 2 6

0

0 5 7 

*/