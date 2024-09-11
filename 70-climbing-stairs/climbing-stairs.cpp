class Solution {
public:
   int solve(int n,int s,vector<int>& dp){
    if(s==n){
        return 1;
    }
    if(s>n){
        return 0;
    }
    if(dp[s]!=-1){
        return dp[s];
    }
    int one = solve(n,s+1,dp);
    int two = solve(n,s+2,dp);
      return dp[s]=one+ two;
   }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return solve(n,0,dp);
    }
};