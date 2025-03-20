class Solution {
public:
   int solve(vector<int>& nums,int start,int end,vector<vector<int>>& dp){
    if(start>end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int ans = 0;
    for(int i = start;i<=end;i++){
    int ans2 = nums[start-1]*nums[i]*nums[end+1] + solve(nums,start,i-1,dp) + solve(nums,i+1,end,dp);
    ans = max(ans2,ans);
    }
    return dp[start][end] = ans;
   }
    int maxCoins(vector<int>& nums) {
         nums.insert(nums.begin(), 1);  
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,1,nums.size()-2,dp);
    }
};