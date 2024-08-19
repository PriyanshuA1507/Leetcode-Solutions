class Solution {
public:
    int solve(vector<int> piles,int p,int index,int M,vector<vector<vector<int>>>& dp){
        int n = piles.size();
        if(index>=n){
            return 0;
        }
        if(dp[p][index][M]!=-1){
            return dp[p][index][M];
        }
         int stones=0;
        int result = (p==1)?-1:INT_MAX;
        for(int x = 1;x<=2*M && index+x<=n;x++){
            
          stones+=piles[index+x-1];
          if(p==1){
            result = max(result, stones + solve(piles,0,index+x,max(M,x),dp));
          }
          else{
             
            result = min(result, solve(piles,1,index+x,max(M,x),dp));
          }
        }
        return dp[p][index][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
      return solve(piles,1, 0, 1,dp);
        
    }
};