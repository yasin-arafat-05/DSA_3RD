
#include<iostream>
#include<vector>
using namespace std;

#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

const int N = 1e5;
vector<pair<int,int>> graph[N];

int main(){
    yasin
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int v1,v2,wt;cin>>v1>>v2>>wt;
        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }

    //_______ Output ___________
    for(int i=0;i<n;i++){
        cout << "----->"<< i << " : ";
        for(pair<int,int> j : graph[i]){
            cout << "( "<<j.first << "," << j.second << " )" << " ";
        }
        cout << endl;
    }
}
/*
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
