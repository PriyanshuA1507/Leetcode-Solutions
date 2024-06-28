class Solution {
public:
    int solve(int n,int index,int e,vector<vector<int>>& dp){
        if(index==1 || index==0){
            return index;
        }
        if(e==1){
            return index;
        }
        if(dp[index][e]!=-1){
            return dp[index][e];
        }
        int minAttempts = INT_MAX;

        for (int x = 1; x <= index; ++x) {
            int broke = solve(n, x - 1, e - 1,dp);
            int notbroke = solve(n, index - x, e,dp);
            int attempts = 1 + max(broke, notbroke);
            minAttempts = min(minAttempts, attempts);
        }

        return dp[index][e]= minAttempts;
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(n,n,2,dp);
    }
};