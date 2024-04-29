

//________________LeetCode Problem______________________


#include<iostream>
#include<vector>
using namespace std;
#define yasin{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor!=color)
            dfs(sr,sc,initialColor,color,image);
        return image;
    }
};

// we don't need visited array cause this is martix representation of graph.

void dfs(int i,int j,int initialColor,int newColor,vector<vector<int>>& image){

    int n = image.size();
    int m = image[0].size();

    // 4-directionally
    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(image[i][j] != initialColor)  return;

    image[i][j] = newColor;

    dfs(i+1,j,initialColor,newColor,image);
    dfs(i-1,j,initialColor,newColor,image);
    dfs(i,j+1,initialColor,newColor,image);
    dfs(i,j-1,initialColor,newColor,image);
    
}


int main(){
    yasin

}