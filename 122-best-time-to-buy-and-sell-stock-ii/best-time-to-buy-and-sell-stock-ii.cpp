class Solution {
public:
    int solve(vector<int>& prices,int index1,bool buy,vector<vector<int>>& dp){
        if(index1>=prices.size()){
         return 0;
        }
        if(dp[index1][buy]!=-1){
            return dp[index1][buy];
        }
      if(!buy){
      int buykar = -prices[index1] + solve(prices,index1+1,true,dp);
      int skipkar = solve(prices,index1+1,false,dp);
      return dp[index1][buy] = max(buykar,skipkar);
      }
      if(buy){
       int sellkar = prices[index1] + solve(prices,index1+1,false,dp);
      int skipkar = solve(prices,index1+1,true,dp);
      return dp[index1][buy] =  max(sellkar,skipkar);
      }
     return dp[index1][buy] = 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(prices,0,false,dp);
        
    }
};