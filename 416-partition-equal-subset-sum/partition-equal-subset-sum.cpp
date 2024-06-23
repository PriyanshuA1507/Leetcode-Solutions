class Solution {
public:
    bool solve(int index,int n,vector<int>& nums,int target,vector<vector<int>>& dp){
      if(index>=n){
        return 0;
      }
      if(target<0){
        return 0;
      }
      if(target==0){
        return 1;
      }
      if(dp[index][target]!=-1){
        return dp[index][target];
      }
    bool incl = solve(index+1,n,nums,target-nums[index],dp);
    bool excl = solve(index+1,n,nums,target,dp);

    return dp[index][target]=(incl||excl);
    }
    bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int totalsum =0;
    for(int i=0;i<nums.size();i++){
        totalsum+=nums[i];
    }
    if(totalsum%2!=0){
        return false;
    }
    int target = totalsum/2;
    vector<vector<int>> dp(n, vector(target+1,-1));
    return solve(0,n,nums,target,dp);
    }
};