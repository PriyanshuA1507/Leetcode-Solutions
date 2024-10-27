class Solution {
public:
    int solve(int amount, vector<int>& coins, int sum, int index,vector<vector<int>>& dp) {
        if (sum == amount) {
            return 1;
        }
        if (sum > amount || index >= coins.size()) {
            return 0;
        }
         if(dp[index][sum]!=-1){
            return dp[index][sum];
         }
        int ans = 0;
       
        ans += solve(amount, coins, sum + coins[index], index,dp);

        ans += solve(amount, coins, sum, index + 1,dp);

        return dp[index][sum]=ans;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(5001,-1));
        return solve(amount, coins, 0, 0,dp);
    }
};