class Solution {
public:
   vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
     void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& visited){
        int n = grid.size(), m= grid[0].size();
      visited[i][j] = true;
      for( auto d: dirs){
    int r = i + d[0];
    int c = j + d[1];
    if(r>=0 && c>=0 && r<n && c<m && !visited[r][c] && grid[r][c]=='1'){
        dfs(grid,r,c,visited);
    }
      }
     }
    int numIslands(vector<vector<char>>& grid) {
    int c = 0;
    int n = grid.size(), m= grid[0].size();
   vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if(grid[i][j]=='1' && !visited[i][j]){
      c++;
      dfs(grid,i,j,visited);
    }
    }
    }
    return c;   
    }
};