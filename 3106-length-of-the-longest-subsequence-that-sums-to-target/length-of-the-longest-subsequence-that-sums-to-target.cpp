class Solution {
public:
    int solve(vector<int>& nums, int index, int t, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return (t == 0) ? 0 : -100000; 
        }
        if (t == 0) {
            return 0; 
        }
        if (dp[index][t] != -1) {
            return dp[index][t]; 
        }

        int take = -1000000;
        if (t >= nums[index]) {
            take = 1 + solve(nums, index + 1, t - nums[index], dp); 
        }

        int notTake = solve(nums, index + 1, t, dp);
        return dp[index][t] = max(take, notTake); 
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int t) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(t + 1, -1)); 
        int ans = solve(nums, 0, t, dp); 
        return ans <= 0 ? -1 : ans; 
    }
};
