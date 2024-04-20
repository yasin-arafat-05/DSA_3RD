
#include<iostream>
using namespace std;

#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N = 1e4;
int graph[N][N];


int main(){
    yasin
    int m,n;cin>>n>>m;

    //_________Input of the graph____________
    for(int i=0;i<m;i++){
        int v1,v2,wt;cin>>v1>>v2>>wt;
        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
    }
    //_________Output of the graph____________
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
}



/*
input:
6 9
1 3 4
1 5 3
3 5 2
3 4 7
3 6 8
3 2 9
2 6 1
4 6 2
5 6 3
*/