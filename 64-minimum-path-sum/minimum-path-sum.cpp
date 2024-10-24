class Solution {
public:
    int solve(vector<vector<int>>& grid,int si,int sj,int m,int n,vector<vector<int>>&dp){
        if(si==m-1 && sj==n-1){
            return grid[si][sj];
        }
        if(si>=m || sj>=n){
            return 1e9;
        }
        if(dp[si][sj]!=-1){
            return dp[si][sj];
        }
        
        int down = grid[si][sj] + solve(grid,si+1,sj,m,n,dp);
        int right = grid[si][sj] + solve(grid,si,sj+1,m,n,dp);

       return dp[si][sj]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(grid,0,0,m,n,dp);
    }
};