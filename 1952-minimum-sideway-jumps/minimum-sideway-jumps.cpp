class Solution {
public:
    int solve(vector<int>& o,int currpos,int currlane,vector<vector<int>>& dp){
        int n = o.size();
        if(currpos==n-1){
            return 0;
        }
        if(dp[currpos][currlane]!=-1){
            return dp[currpos][currlane];
        }
        if(o[currpos+1]!=currlane){
            return solve(o,currpos+1,currlane,dp);
        }
    
        int ans = INT_MAX;
        for(int i=1;i<=3;i++){
        if(currlane!=i && o[currpos]!=i){
        ans = min(ans, 1+solve(o,currpos,i,dp));
        }
        }
        return dp[currpos][currlane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size(); 
    vector<vector<int>> dp(n+1,vector<int>(4,-1));
    return solve(obstacles,0,2,dp);
    }
};