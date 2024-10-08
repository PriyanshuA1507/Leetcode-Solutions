class Solution {
public:
    int solve(vector<int>& cost,int index,vector<int>& dp){
        if(index>=cost.size()){
         return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int a = cost[index] + solve(cost,index+1,dp);
        int b = cost[index] + solve(cost,index+2,dp);
        return dp[index]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};