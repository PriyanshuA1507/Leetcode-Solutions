class Solution {
public:
   int solve(vector<int>& nums,int sum,int index,vector<vector<int>>& dp){
    if(sum==0){
        return 1;
    }
    if(index>=nums.size() || sum<0){
        return 0;
    }
    if(dp[sum][index]!=-1){
        return dp[sum][index];
    }
    bool take = solve(nums,sum-nums[index],index+1,dp);
    bool nottake = solve(nums,sum,index+1,dp);
    return dp[sum][index]=(take||nottake);
   }
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      int sum = 0;
      for( int a :nums){
        sum+=a;
      }   
      if(sum%2!=0){
        return false;
      }
      vector<vector<int>> dp(sum/2+1,vector<int>(n+1,-1));
      return solve(nums,sum/2,0,dp);
    }
};