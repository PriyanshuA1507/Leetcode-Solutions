class Solution {
public:
    bool solve(vector<int>& nums,int index,int n,vector<int>& dp){

        if(index==n-1){
            return true;
        }
        if(index>=n){
            return false;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=1;i<=nums[index];i++){
            if(solve(nums,index+i,n,dp)){
            return dp[index+i] =true;
            }
        }
        return dp[index]= false;
    }
    bool canJump(vector<int>& nums) {
        int n = 100000;
        vector<int> dp(n+1,-1);
        return solve(nums,0,nums.size(),dp);
    }
};