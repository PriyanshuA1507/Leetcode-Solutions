class Solution {
public:
   int solve(vector<int>& prices,int index,bool buy,int k,vector<vector<vector<int>>>& dp){
    if(index==prices.size()){
        return 0;
    }
    if(k==0){
        return 0;
    }
    if(dp[index][buy][k]!=-1){
        return dp[index][buy][k];
    }
    int ans =0;
    if(buy){
     int buykaro = -prices[index]  + solve(prices,index+1,0,k,dp);
     int skipkaro = 0  + solve(prices,index+1,1,k,dp);
     ans = max(buykaro,skipkaro);
    }
    if(!buy ){
     int sellkaro = prices[index]  + solve(prices,index+1,1,k-1,dp);
     int skipkaro = 0  + solve(prices,index+1,0,k,dp);
       ans = max(sellkaro,skipkaro);
    }
    return dp[index][buy][k] = ans;
   }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
       return solve(prices,0,1,2,dp); 
    }
};