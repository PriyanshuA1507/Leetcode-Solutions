class Solution {
public:
    int solve(string &s, int si, int ei,vector<vector<int>>& dp) {
        
        if (si >= ei) {
            return 0;
        }
        if(dp[si][ei]!=-1){
            return dp[si][ei];
        }
        
        if (s[si] == s[ei]) {
            return solve(s, si + 1, ei - 1,dp);
        }
       
    
        int insertAtStart = 1 + solve(s, si + 1, ei,dp);
        int insertAtEnd = 1 + solve(s, si, ei - 1,dp);
        
      
        return dp[si][ei]=min(insertAtStart, insertAtEnd);
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s, 0, s.size() - 1,dp);
    }
};