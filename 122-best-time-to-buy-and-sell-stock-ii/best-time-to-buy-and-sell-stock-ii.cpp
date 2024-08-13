class Solution {
public:
    int solve(vector<int>& prices, int index,int b,vector<vector<int>>& dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][b]!=-1){
            return dp[index][b];
        }
        int profit = 0;
        if(b==1){
        int buykaro = -prices[index] + solve(prices,index+1,0,dp);
        int skipkaro = 0 +solve(prices,index+1,1,dp);
        profit = max(buykaro,skipkaro);
        }
        else{
        int sellkaro = prices[index] + solve(prices,index+1,1,dp);
        int skipkaro = 0 +solve(prices,index+1,0,dp);
        profit = max(sellkaro, skipkaro);
        }
        return dp[index][b]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(prices,0,1,dp);
    }
};