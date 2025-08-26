class Solution {
public:
    const int m1 = 1000000000 + 7;

    int solve(vector<vector<int>>& grid, int si, int sj, int sumMod, int k,
              vector<vector<vector<int>>>& dp) {
        int m = grid.size(), n = grid[0].size();

        // Base case: reached bottom-right cell
        if (si == m - 1 && sj == n - 1) {
            return (sumMod % k == 0) ? 1 : 0;
        }

        // If already computed
        if (dp[si][sj][sumMod] != -1) {
            return dp[si][sj][sumMod];
        }

        int down = 0, right = 0;

        // Move down
        if (si + 1 < m) {
            down = solve(grid, si + 1, sj, (sumMod + grid[si + 1][sj]) % k, k, dp);
        }

        // Move right
        if (sj + 1 < n) {
            right = solve(grid, si, sj + 1, (sumMod + grid[si][sj + 1]) % k, k, dp);
        }

        return dp[si][sj][sumMod] = (down + right) % m1;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));


        return solve(grid, 0, 0, grid[0][0] % k, k, dp);
    }
};
