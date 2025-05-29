class Solution {
public:
   vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid,int i,int j){
    grid[i][j]=1;
    for(auto d:dir){
    int newi = i + d[0];
    int newj = j + d[1];
    if(newi>=0 && newj>=0 && newi<grid.size() && newj<grid[0].size() && grid[newi][newj]==0){
    dfs(grid,newi,newj);
    }
    }
    }

    void dfs2(vector<vector<int>>& grid,int i,int j, vector<vector<bool>>& visited){
    visited[i][j]=true;
    for(auto d:dir){
    int newi = i + d[0];
    int newj = j + d[1];
    if(newi>=0 && newj>=0 && newi<grid.size() && newj<grid[0].size() && grid[newi][newj]==0 && !visited[newi][newj]){
    dfs(grid,newi,newj);
    }
    }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
     for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
        if((i==0 || j==0 || i==m-1 || j== n-1)&& grid[i][j]==0){
         dfs(grid,i,j);
        }
     }
     }
     int ans = 0;
     vector<vector<bool>> visited(m,vector<bool>(n,false));
     for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
        if(grid[i][j]==0 && !visited[i][j]){
         dfs2(grid,i,j,visited);
         ans++;
        }
     }
     }
     return ans;
    }
};