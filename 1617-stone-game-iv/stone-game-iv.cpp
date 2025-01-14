class Solution {
public:
    bool solve(int n,vector<int>& dp){
        if(n==0){
            return false; 
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a = sqrt(n);
        for(int i=1;i<=a;i++){
       if(!solve(n-(i*i),dp)){
        return dp[n]=true;
       }
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
    vector<int> dp(n+1,-1);
    return solve(n,dp);    
    }
};