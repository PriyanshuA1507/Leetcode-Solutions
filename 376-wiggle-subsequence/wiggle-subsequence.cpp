class Solution {
public:
    int solve(vector<int>& nums,int index,bool p,vector<vector<int>>& dp){
     if(index>=nums.size()){
        return 0;
     }
     if(dp[index][p]!=-1){
        return dp[index][p];
     }
    int take = 0;
     if((nums[index-1]-nums[index]<0 && p)||(nums[index-1]-nums[index]>0 && !p)){
    take = 1 + solve(nums,index,!p,dp);
     }
      int nottake = solve(nums,index+1,p,dp);

     return dp[index][p]=max(take,nottake);
     
    }
    int wiggleMaxLength(vector<int>& nums) {
    
      if(nums.size()<2){
        return nums.size();
      }  
      int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
      return 1 + max(solve(nums,1,false,dp),solve(nums,1,true,dp));

    }
};