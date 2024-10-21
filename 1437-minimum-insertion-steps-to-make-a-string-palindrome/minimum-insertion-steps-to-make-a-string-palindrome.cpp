class Solution {
public:
    int solve(string &s, int si, int ei, vector<vector<int>>& dp) {
        // Base case: when si exceeds ei, no more insertions are needed
        if (si >= ei) {
            return 0;
        }

        // If the result is already computed, return it
        if (dp[si][ei] != -1) {
            return dp[si][ei];
        }

        // If the characters match, no insertions are needed, just move inward
        if (s[si] == s[ei]) {
            return dp[si][ei] = solve(s, si + 1, ei - 1, dp);
        }

        // Otherwise, find the minimum insertions by either inserting at the beginning or the end
        int insertAtLast = 1 + solve(s, si + 1, ei, dp);
        int insertAtBegin = 1 + solve(s, si, ei - 1, dp);

        // Store the result in the dp table and return the minimum of the two options
        return dp[si][ei] = min(insertAtLast, insertAtBegin);
    }

    int minInsertions(string s) {
        int n = s.size();
        // Initialize dp table with size n x n filled with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // Call the recursive function starting from the full string
        return solve(s, 0, n - 1, dp);
    }
};
