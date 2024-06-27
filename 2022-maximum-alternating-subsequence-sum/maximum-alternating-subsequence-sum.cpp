class Solution {
public:
    long long solve(vector<int>& nums, long long index, long long n, bool add,vector<vector<long long>>& dp) {
        if (index >= n) {
            return 0;
        }
        if(dp[index][add]!=-1){
            return dp[index][add];
        }
        long long take = (add ? nums[index] : -nums[index]) + solve(nums, index + 1, n, !add,dp);
        long long nottake = solve(nums, index + 1, n, add,dp);
        return dp[index][add]=max(take, nottake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(3,-1));
        return solve(nums, 0, n, true,dp);
    }
};
