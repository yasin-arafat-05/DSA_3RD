
//________________LeetCode Problem______________________

#include<iostream>
#include<vector>

using namespace std;

void dfs(int i, int j, vector<vector<char>>& grid,int n,int m){

    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(grid[i][j]!='1') return;

    grid[i][j] = '2';

    dfs(i,j-1,grid,n,m);
    dfs(i,j+1,grid,n,m);
    dfs(i-1,j,grid,n,m);
    dfs(i+1,j,grid,n,m);

}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
        int n = grid.size();
        if (n==0) return 0;
        int m = grid[0].size();
        int cnt =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                dfs(i,j,grid,n,m);
                cnt++;
                }
            }
        }

        return cnt;
    }
};




int main(){}





