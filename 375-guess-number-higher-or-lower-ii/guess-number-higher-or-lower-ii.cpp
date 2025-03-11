class Solution {
public:
 int solve(int start,int end, vector<vector<int>>& dp){
 if(start>=end){
    return 0;
 }
 if(dp[start][end]!=-1){
    return dp[start][end];
 }
 int ans = 1e8;
 for(int i=start;i<=end;i++){
 int ans2 = i + max(solve(start,i-1,dp), solve(i+1,end,dp));
 ans = min(ans2,ans);
 }
 return dp[start][end]=ans;
 }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);
    }
};