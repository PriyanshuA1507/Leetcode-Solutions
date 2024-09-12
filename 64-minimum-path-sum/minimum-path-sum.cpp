class Solution {
public:
    int solve(int si,int sj,vector<vector<int>>& grid,int r,int c,vector<vector<int>>& dp){
        if(si>=r || sj>=c){
            return 1e8;
        }
        if(si==r-1 && sj == c-1){
            return grid[si][sj];
        }
        if(dp[si][sj]!=-1){
            return dp[si][sj];
        }
        int down = grid[si][sj] + solve(si+1,sj,grid,r,c,dp);
        int right = grid[si][sj] + solve(si,sj+1,grid,r,c,dp);

        return dp[si][sj]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,grid,grid.size(),grid[0].size(),dp);
    }
};