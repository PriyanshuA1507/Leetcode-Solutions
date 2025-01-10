class Solution {
public:
    int solve(vector<int>& prices,int index1,bool buy,int t,vector<vector<vector<int>>>& dp){
        if(index1>=prices.size()){
         return 0;
        }
        if(dp[index1][buy][t]!=-1){
            return dp[index1][buy][t];
        }
      if(!buy && t>0){
      int buykar = -prices[index1] + solve(prices,index1+1,true,t,dp);
      int skipkar = solve(prices,index1+1,false,t,dp);
      return dp[index1][buy][t] = max(buykar,skipkar);
      }
      if(buy){
       int sellkar = prices[index1] + solve(prices,index1+1,false,t-1,dp);
      int skipkar = solve(prices,index1+1,true,t,dp);
      return dp[index1][buy][t] =  max(sellkar,skipkar);
      }
     return dp[index1][buy][t] = 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(prices,0,false,2,dp);
        
    }
};