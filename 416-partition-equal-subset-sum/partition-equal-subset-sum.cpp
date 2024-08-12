class Solution {
public:
    int solve(vector<int>& nums,int index,int target,vector<vector<int>>& dp){
        int n = nums.size();
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
        int incl = solve(nums,index+1,target-nums[index],dp);
        int excl = solve(nums,index+1,target,dp);
        return dp[index][target]=incl||excl;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int a:nums){
            total+=a;
        }
        if(total%2!=0){
            return 0;
        }
        int target = total/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(nums,0,target,dp);
    }
};