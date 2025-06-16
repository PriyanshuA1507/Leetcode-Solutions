class Solution {
public:
    bool solve(vector<int>& nums,int index,vector<int>& dp){
    if(index==nums.size()-1){
        return true;
    }
    if(index>=nums.size()){
        return false;
    }
    
    if(dp[index]!=-1){
        return dp[index];
    }
    bool ans = false;
    for(int i=1;i<=nums[index];i++){
    if (solve(nums, index + i, dp)) {
                ans = true;
                break; 
            }
    }
    return dp[index]= ans;
    }
    bool canJump(vector<int>& nums) {
    int n = nums.size();
     vector<int> dp(n+1,-1);
     return solve(nums,0,dp);   
    }
};