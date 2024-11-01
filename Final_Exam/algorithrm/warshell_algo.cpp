
#include<iostream>
#include<algorithm>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
const int N = 1e4;
const int INF = 1e6;
int graph[N][N];

int main(){
    yasin

    //--------------- take input ---------------
    int m,n;
    cin>>m>>n;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int wt;cin>>wt;
            if(wt==0){
                graph[i][j] = INF;
            }else{
                graph[i][j] = wt;
            }
        }
    }

//------------- warshell algorithrm ----------------
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j] = min(graph[i][j],(graph[i][k]+graph[k][j]));
        }
    }
}
// ----------------- print space ----------------------

cout<<endl<<endl;

// ------------- show the output ----------------------
 for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==INF){
                cout<<"INF"<<" ";
            }else{
                cout<<graph[i][j]<<"  ";
            }
        }
        cout<<endl;
    }
}

/*

4 4
7 5 0 0
7 0 0 2
0 3 0 0
4 0 1 0 

*/

