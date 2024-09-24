class Solution {
public:
     int solve(vector<int>& nums,int index,vector<int>& dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int a = nums[index] + solve(nums,index+2,dp);
        int b = solve(nums,index+1,dp);
        return dp[index]= max(a,b);
     }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
       return max(solve(nums,0,dp) ,solve(nums,1,dp));
    }
};