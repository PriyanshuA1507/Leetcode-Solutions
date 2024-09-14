class Solution {
public:
 const int mod = 1000000007;
    int solve(int low,int high,int zero,int one,int l,vector<int>& dp){
       if(l>high){
        return 0;
       }
       if(dp[l]!=-1){
        return dp[l];
       }
       bool addone = false;
       if(l>=low){
        addone = true;
       }
       int appendzero = solve(low,high,zero,one,l+zero,dp);
       int appendone = solve(low,high,zero,one,l+one,dp);

       return dp[l]=(addone + appendzero + appendone)%mod ;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return solve(low,high,zero,one,0,dp);
    }
};