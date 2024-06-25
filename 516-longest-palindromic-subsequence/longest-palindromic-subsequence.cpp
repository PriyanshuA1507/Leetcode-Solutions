#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int solve(const std::string& text1, const std::string& text2, int i, int j, std::vector<std::vector<int>>& dp) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
        } else {
            ans = std::max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
        }
        return dp[i][j] = ans;
    }

    int longestPalindromeSubseq(std::string s) {
        int n = s.size();
        std::string s1 = s;
        std::reverse(s1.begin(), s1.end());
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
        return solve(s, s1, 0, 0, dp);
    }
};
