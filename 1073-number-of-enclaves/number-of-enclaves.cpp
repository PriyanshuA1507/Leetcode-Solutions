class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
     int m = grid.size();
     int n  = grid[0].size();
     queue<pair<int,int>> q;
     vector<vector<bool>> visited(m,vector<bool>(n,false));
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
            if(i==0 || j==0|| i==m-1 || j==n-1){
                q.push({i,j});
                visited[i][j]=true;
                grid[i][j] = -1;
            }
            }
        }
     }
     vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
     while(!q.empty()){
      auto a = q.front();
      q.pop();
      for(auto &a1:dir){
        int r = a1[0] + a.first;
        int c = a1[1] + a.second;
    if(r>=0 && c>=0 && r<m && c<n && !visited[r][c] && grid[r][c]==1){
        visited[r][c] = true;
        grid[r][c] = -1;
        q.push({r,c});
    }
      }
     }
     int ans = 0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                ans++;
            }
        }
     }
     return ans;

    }
};