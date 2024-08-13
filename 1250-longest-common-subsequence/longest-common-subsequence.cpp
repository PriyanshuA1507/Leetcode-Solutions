class Solution {
public:
    int solve(string &text1, string &text2, int i1, int i2, vector<vector<int>> &dp) {
        if (i1 >= text1.size() || i2 >= text2.size()) {
            return 0; // Base case: If either string is exhausted
        }

        if (dp[i1][i2] != -1) {
            return dp[i1][i2]; // Return cached result if already computed
        }

        int take = 0;
        if (text1[i1] == text2[i2]) {
            take = 1 + solve(text1, text2, i1 + 1, i2 + 1, dp);
        }
        int skipText1 = solve(text1, text2, i1 + 1, i2, dp);
        int skipText2 = solve(text1, text2, i1, i2 + 1, dp);

        return dp[i1][i2] = max({take, skipText1, skipText2});
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1)); // DP table initialization
        return solve(text1, text2, 0, 0, dp);
    }
};
