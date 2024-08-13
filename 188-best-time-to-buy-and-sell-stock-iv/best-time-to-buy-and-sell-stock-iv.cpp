class Solution {
public:
   int solve(vector<int>& prices,int index,int b,int k,vector<vector<vector<int>>>& dp){
    if(index>=prices.size()){
        return 0;
    }
    if(k==0){
        return 0;
    }
    if(dp[index][b][k]!=-1){
        return dp[index][b][k];
    }
    int profit = 0;
        if(b==1){
        int buykaro = -prices[index] + solve(prices,index+1,0,k,dp);
        int skipkaro = 0 +solve(prices,index+1,1,k,dp);
        profit = max(buykaro,skipkaro);
        }
        else{
        int sellkaro = prices[index] + solve(prices,index+1,1,k-1,dp);
        int skipkaro = 0 +solve(prices,index+1,0,k,dp);
        profit = max(sellkaro , skipkaro);
   }
   return dp[index][b][k]=profit;
   }
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices,0,1,k,dp);
    }
};