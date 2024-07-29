class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>> dir,int &a){
        grid[i][j]=0;
        int n = grid.size(),m= grid[0].size();
        for(int d=0;d<dir.size();d++){
        int r = i+dir[d][0];
        int c = j+dir[d][1];
       if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1)
       dfs(grid,r,c,dir,a+=1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
            int a = 1;
            dfs(grid,i,j,dir,a);
            ans = max(ans,a);
            }
        }
        }

        return ans;
    }
};