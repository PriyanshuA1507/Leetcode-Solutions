class Solution {
public:
    int solve(string s, string t,int i,int j, vector<vector<int>>& dp){
        if(j>=t.size()){
            return 1;
        }
        if(i>=s.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a= solve(s,t,i+1,j,dp);
        int b = 0;
        if(s[i]==t[j]){
            b= solve(s,t,i+1,j+1,dp);
        }
        return dp[i][j]=a+b;
    }
    int numDistinct(string s, string t) {
        int n = max(s.size(),t.size());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
         return solve(s,t,0,0,dp);
    }
};