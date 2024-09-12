class Solution {
public:

     
    int solve(vector<int>& jd, int d, int index,vector<vector<int>>& dp) {     
        if (index == jd.size()) {
            if(d==0){
            return 0;
            }
           return INT_MAX;
        }
        if (d == 0) {
            return INT_MAX;
        }
        if(dp[d][index]!=-1){
         return dp[d][index];
        }
       int ma = 0;
       int ans = INT_MAX;
       for(int i=index;i<jd.size();++i){
         ma = max(ma,jd[i]);
     int next = solve(jd,d-1,i+1,dp);
      if(next!=INT_MAX){
    ans = min(ans,ma+next);
      }
      }
      return dp[d][index]=ans;
    }

  
    int minDifficulty(vector<int>& jd, int d) {
        if (d > jd.size()) {
            return -1;
        }
        int n = jd.size();
        vector<vector<int>> dp(d+1,vector<int>(n+1,-1));
        int ans = solve(jd, d,0,dp);
        
   
        return (ans == INT_MAX) ? -1 : ans;
    }
};
