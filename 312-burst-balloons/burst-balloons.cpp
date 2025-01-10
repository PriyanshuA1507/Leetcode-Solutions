class Solution {
public:
   int solve(vector<int>& nums,int si,int ei,vector<vector<int>>& dp){
    if(si>ei){
        return 0;
    }
    if(dp[si][ei]!=-1){
        return dp[si][ei];
    }
    int ans = INT_MIN;
    for(int i=si;i<=ei;i++){
     int coins = nums[si-1]*nums[i]*nums[ei+1] + solve(nums,si,i-1,dp) + solve(nums,i+1,ei,dp);
     ans = max(ans,coins);
    }
    return dp[si][ei]=ans;
   }
    int maxCoins(vector<int>& nums) {
     nums.insert(nums.begin(), 1);  
     nums.push_back(1);   
     int n = nums.size();
     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
     return solve(nums,1,n-2,dp);
    }
};