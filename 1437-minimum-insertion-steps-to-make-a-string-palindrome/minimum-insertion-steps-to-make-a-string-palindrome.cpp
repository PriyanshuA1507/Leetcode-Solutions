class Solution {
public:
    int solve(string& s, int si,int ei,vector<vector<int>>& dp){
        if(si>=ei){
            return 0;
        }
        if(dp[si][ei]!=-1){
            return dp[si][ei];
        }
        if(s[si]==s[ei]){
        return dp[si][ei]=solve(s,si+1,ei-1,dp);
        }
        int insertatlast = 1+solve(s,si+1,ei,dp);
        int insertatbegin = 1+ solve(s,si,ei-1,dp);
        
        return dp[si][ei]=min({insertatlast,insertatbegin});
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return solve(s,0,n-1,dp);

    }
};