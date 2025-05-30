class Solution {
public:
   bool solve(vector<int>& nums,int index,vector<int>& dp){
    int n = nums.size();
    if(index==n-1){
        return true;
    }
    if(index>=n){
        return false;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    for(int i = 1;i<=nums[index];i++){
    if(solve(nums,index+i,dp)){
        return dp[index+i]=true;
    }
    }
    return dp[index]= false;
   }
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,0,dp);
    }
};