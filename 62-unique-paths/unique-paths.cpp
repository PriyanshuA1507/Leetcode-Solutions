class Solution {
public:
    int solve(int si, int sj, int m, int n, vector<vector<int>>& dp) {
        if (si == m || sj == n) {
            return 0;
        }
        if (si == m - 1 && sj == n - 1) {
            return 1;
        }
        if (dp[si][sj] != -1) {
            return dp[si][sj];
        }
        int down = solve(si + 1, sj, m, n, dp);
        int right = solve(si, sj + 1, m, n, dp);
        dp[si][sj] = down + right;
        return dp[si][sj];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};
