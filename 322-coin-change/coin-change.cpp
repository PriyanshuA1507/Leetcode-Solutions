class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>& dp){
        if(amount<0){
            return 1e8;
        }
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int c = 1e8;
        for(int i=0;i<coins.size();i++){
         int ans = 1 + solve(coins,amount-coins[i],dp);
         c = min(c,ans);
        }
        return dp[amount]=c;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
     int ans = solve(coins,amount,dp); 
     if(ans>=1e8){
        return -1;
     }  
     return ans;
    }
};