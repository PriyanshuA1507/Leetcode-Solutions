class Solution {
public:
    int solve(vector<vector<int>>& mat, int target, int sr, int currentSum, vector<vector<int>>& dp, int offset) {
        if (sr == mat.size()) {
            return abs(currentSum - target);
        }
        if (dp[sr][currentSum + offset] != -1) {
            return dp[sr][currentSum + offset];
        }

        int mini = INT_MAX;
        for (int j = 0; j < mat[sr].size(); j++) {
            mini = min(mini, solve(mat, target, sr + 1, currentSum + mat[sr][j], dp, offset));
        }

        return dp[sr][currentSum + offset] = mini;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int maxSum = 0;
        for (int i = 0; i < m; i++) {
            maxSum += *max_element(mat[i].begin(), mat[i].end());
        }

        int offset = maxSum;
        vector<vector<int>> dp(m, vector<int>(2 * maxSum + 1, -1));

        return solve(mat, target, 0, 0, dp, offset);
    }
};

