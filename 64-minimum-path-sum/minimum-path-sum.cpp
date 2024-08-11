class Solution {
public:
    int solve(vector<vector<int>>& grid, int si, int sj, int n, int m,vector<vector<int>>& dp) {
        if (si >= n || sj >= m) {
            return INT_MAX;
        }
        if (si == n - 1 && sj == m - 1) {
            return grid[si][sj];
        }
        if(dp[si][sj]!=-1){
            return dp[si][sj];
        }
        int down = solve(grid, si + 1, sj, n, m,dp);
        int right = solve(grid, si, sj + 1, n, m,dp);
        return dp[si][sj]=grid[si][sj]+ min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(grid, 0, 0, n, m,dp);
    }
};
