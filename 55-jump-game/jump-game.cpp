class Solution {
public:
   bool solve(vector<int>& nums,int index,vector<int>& dp){
   if(index>=nums.size()-1){
    return true;
   }

   if(dp[index]!=-1){
    return dp[index];
   }
   for(int i=1;i<=nums[index];i++){
      if(solve(nums,index+i,dp)){
      return true;
   }
   }
   return dp[index] = false;
   }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        vector<int> dp(nums.size(),-1);
       return solve(nums,0,dp); 
    }
};