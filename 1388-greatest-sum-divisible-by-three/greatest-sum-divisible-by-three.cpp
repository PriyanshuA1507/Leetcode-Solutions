class Solution {
public:
    int solve(vector<int>& nums, int index, int mod, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            if(mod==0)
            return 0;
            return INT_MIN;
        }

        if (dp[index][mod] != -1) {
            return dp[index][mod];
        }

        int include = nums[index]+solve(nums, index + 1, (mod+ nums[index])%3, dp);
        int exclude = solve(nums, index + 1,mod, dp);

        return dp[index][mod] = max(include, exclude);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));

        return solve(nums, 0, 0, dp);
    }
};
