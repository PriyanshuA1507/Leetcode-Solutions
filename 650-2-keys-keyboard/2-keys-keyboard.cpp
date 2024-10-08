class Solution {
public:
    int solve(int n, int ol,int cl,vector<vector<int>>& dp){
        if(ol>n){
            return 1e9;
        }
        if(ol==n){
            return 0;
        }
        if(dp[ol][cl]!=-1){
            return dp[ol][cl];
        }
       int c1 = 2 + solve(n,2*ol,ol,dp);
       
       int p = 1 + solve(n,ol+cl,cl,dp);

       return  dp[ol][cl]=min(c1,p);
    }
    int minSteps(int n) {
        if(n<=1){
            return 0;
        }
       int ol = 1;
       int cl = 1;
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return 1+solve(n,1,1,dp);
    }
};