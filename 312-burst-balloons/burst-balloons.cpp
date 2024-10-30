class Solution {
public:
  long long solve(vector<int>& nums,int start,int end, vector<vector<int>>& dp){
    if(start>end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    long long ans = LLONG_MIN;
    for(int k = start;k<=end;k++){
 long long coins = (long long)nums[start - 1] * nums[k] * nums[end + 1];
            coins += solve(nums, start, k - 1,dp) + solve(nums, k + 1, end, dp);
            ans = max(ans, coins);
    }
    return dp[start][end]=ans;
   }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
         vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
       return solve(nums,1,nums.size()-2,dp);
    }
};