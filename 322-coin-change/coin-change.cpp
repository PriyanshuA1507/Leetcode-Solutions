class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>& dp){
        if(amount==0){
        return 0;
    }
    if(amount<0){
        return 1e8;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }
    int ans = 1e8;
    for(int i=0;i<coins.size();i++){
    ans = min(ans, 1 + solve(coins,amount-coins[i],dp));
    }
    return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
      int a = solve(coins,amount,dp);  
      if(a>=1e8){
        return -1;
      } 
      else{
       return a;
      }
      return 0;
    }
};