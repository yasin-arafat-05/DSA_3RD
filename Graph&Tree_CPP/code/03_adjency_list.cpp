
#include<iostream>
#include<vector>
using namespace std;

#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

const int N = 1e5;
vector<int> graph[N];

int main(){
    yasin
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

      // Output
    for(int i=0;i<n;i++){
        cout << "----->"<< i << ": ";
        for(int j : graph[i]){
            cout << j << " ";
        }
        cout << endl;
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