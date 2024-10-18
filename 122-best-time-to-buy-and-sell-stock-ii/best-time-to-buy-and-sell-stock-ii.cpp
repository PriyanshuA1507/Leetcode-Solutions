class Solution {
public:
    int solve(vector<int>& prices,int index,bool buy, vector<vector<int>>& dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit = 0;
        if(!buy){
        int buykaro = -prices[index]+solve(prices,index+1,true,dp);
        int skipkaro = 0+solve(prices,index+1,false,dp);
        profit = max(buykaro,skipkaro);
        }
        else{
        int sellkaro = prices[index] + solve(prices,index+1,false,dp);
         int skipkaro = 0+solve(prices,index+1,true,dp);
         profit = max(sellkaro,skipkaro);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3,-1));
        return solve(prices,0,false,dp);
    }
};