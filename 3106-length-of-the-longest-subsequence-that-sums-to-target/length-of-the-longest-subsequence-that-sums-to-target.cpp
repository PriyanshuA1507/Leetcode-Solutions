class Solution {
public:
    int solve(vector<int>& nums, int index, int t, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return (t == 0) ? 0 : -100000; // Base case: return 0 if target is achieved, otherwise -100000
        }
        if (t == 0) {
            return 0; // Base case: if the target sum t is 0, return 0
        }
        if (dp[index][t] != -1) {
            return dp[index][t]; // Return memoized result if available
        }

        int take = -100000; // Initialize take with a large negative value
        if (t >= nums[index]) {
            take = 1 + solve(nums, index + 1, t - nums[index], dp); // Take the current element
        }

        int notTake = solve(nums, index + 1, t, dp); // Don't take the current element

        return dp[index][t] = max(take, notTake); // Memoize and return the result
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int t) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(t + 1, -1)); // Initialize dp table with -1
        int ans = solve(nums, 0, t, dp); // Start the recursive function from index 0
        return ans <= 0 ? -1 : ans; // If no valid subsequence is found, return -1
    }
};
