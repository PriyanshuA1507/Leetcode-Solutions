class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int, int> dp; // dp[x] stores the length of the longest subsequence ending at x
        int ans = 1;

        for (int i = 0; i < arr.size(); i++) {
            int prev = arr[i] - d;
            // dp[arr[i]] will be dp[prev] + 1 if prev exists, otherwise it will be 1 (new sequence)
            dp[arr[i]] = dp[prev] + 1;
            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};
