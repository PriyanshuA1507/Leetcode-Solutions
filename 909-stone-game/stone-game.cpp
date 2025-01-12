class Solution {
public:
   int solve(vector<int>& piles,int start,int end,vector<vector<int>>& dp){
    if(start>end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int takestart = piles[start] + min(solve(piles,start+2,end,dp), solve(piles,start+1,end-1,dp));
    int takeend = piles[end] + min(solve(piles,start+1,end-1,dp), solve(piles,start,end-2,dp));
    return dp[start][end] = max(takestart,takeend);
   }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
     int p1= solve(piles,0,n-1,dp);  
     int sum = 0;

     for(auto a:piles){
        sum+=a;
     } 
     if(p1>sum-p1){
        return true;
     }
     return false;
    }
};