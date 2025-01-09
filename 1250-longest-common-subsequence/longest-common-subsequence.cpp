#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(string& text1, string& text2, int index1, int index2, vector<vector<int>>& dp) {
        if (index1 >= text1.size() || index2 >= text2.size()) {
            return 0;
        }
        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }
        int o1 = 0;
        if (text1[index1] == text2[index2]) {
            o1 = 1 + solve(text1, text2, index1 + 1, index2 + 1, dp);
        }
        int o2 = solve(text1, text2, index1, index2 + 1, dp);
        int o3 = solve(text1, text2, index1 + 1, index2, dp);

        return dp[index1][index2] = max({o1, o2, o3});
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
