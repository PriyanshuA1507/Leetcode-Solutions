class Solution {
public:
  
  /* int solve(vector<int>& nums,int index,int pi1,int pi2,vector<vector<vector<int>>>& dp){
     if(index>=nums.size()){
        return 0;
     }
       if(dp[index][pi1+1][pi2+1]!=-1){
        return dp[index][pi1+1][pi2+1];
       }
       int take = 0;
       if(pi1==-1|| pi2==-1|| abs(nums[pi1]-nums[pi2])>=abs(nums[index]-nums[pi1])){
        take = 1 + solve(nums,index+1,index,pi1,dp);
       }
       int nottake = solve(nums,index+1,pi1,pi2,dp);

       return dp[index][pi1+1][pi2+1]=max(take,nottake);
   }
    int longestSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
    return solve(nums,0,-1,-1,dp);
    }
    */
      int longestSubsequence(vector<int>& nums) {
        vector<vector<int>> dp(302, vector<int>(302));

        for (int i = nums.size() - 1; i >= 0; --i){
            int num = nums[i];
    
            for (int next = 1; next <= 300; ++next){
                int diff = abs(next - num);
                dp[num][diff] = max(dp[num][diff], dp[next][diff] + 1);
            }

            for (int j = 1; j <= 300; ++j){
                dp[num][j] = max(dp[num][j], dp[num][j - 1]);
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i <= 301; ++i){
            for (int j = 0; j <= 301; ++j){
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};