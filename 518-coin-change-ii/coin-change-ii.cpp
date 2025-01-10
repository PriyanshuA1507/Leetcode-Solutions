class Solution {
public:
    int solve(int amount,vector<int>& coins,int index, vector<vector<int>>& dp){
     if(amount<0){
        return 0;
     }
     if(amount==0){
        return 1;
     }
     if(index>=coins.size()){
        return 0;
     }
     if(dp[amount][index]!=-1){
        return dp[amount][index];
     }
     int take = solve(amount-coins[index],coins,index,dp);
     int nottake = solve(amount,coins,index+1,dp);
     return  dp[amount][index]=take+nottake;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        return solve(amount,coins,0,dp);
    }
};