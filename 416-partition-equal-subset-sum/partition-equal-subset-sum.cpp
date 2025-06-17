class Solution {
public:
    bool solve(vector<int>& nums,int index,int target,vector<vector<int>>& dp){
    if(index==nums.size()-1 && target==0){
        return true;
    }
    if(target<0 || index>=nums.size()){
        return false;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool take;
    if(index+1<nums.size()){
   take = solve(nums,index+1,target-nums[index],dp);
    }
    bool nottake = solve(nums,index+1,target,dp);

    return dp[index][target] = take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
     int sum = 0;
     for(auto a:nums){
     sum+=a;
     }   
     if(sum%2!=0){
        return false;
     }
     vector<vector<int>> dp(n,vector<int>(sum,-1));
     return solve(nums,0,sum/2,dp);
    }
};