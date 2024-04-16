
#include<iostream>
using namespace std;

#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

const int N = 1e4;
int graph[N][N];

int main(){
    yasin
    int m,n;cin>>m>>n;

    //_________Input of the graph____________
    for(int i=0;i<m;i++){
        int v1,v2;cin>>v1,v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    //_________Output of the graph____________
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
}

/*
Input:
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