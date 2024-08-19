class Solution {
public:
    int solve(vector<int>& piles,int si,int ei,vector<vector<int>>& dp){
        if(si>ei){
            return 0;
        }
        if(dp[si][ei]!=-1){
            return dp[si][ei];
        }
    int a = piles[si]+min(solve(piles,si+2,ei,dp),solve(piles,si+1,ei-1,dp));
     int b = piles[ei]+min(solve(piles,si+1,ei-1,dp),solve(piles,si,ei-2,dp));
     return dp[si][ei]=max(a,b);
      
    }
    bool stoneGame(vector<int>& piles) {
     int sum = 0;
     int n = piles.size();
     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans = solve(piles,0,piles.size()-1,dp);
    for(int i=0;i<piles.size();i++){
        sum+=piles[i];
    }
    if(ans>sum-ans){
     return true;   
    }
    return false;
    }
};