class Solution {
public:
    int solve(vector<int>& s,int index,int time,vector<vector<int>>& dp){
        int n = s.size();
        if(index>=n){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        int take = s[index]*(time+1) + solve(s,index+1,time+1,dp);
        int nottake = solve(s,index+1,time,dp);
        return dp[index][time]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        vector<vector<int>> dp(501,vector<int>( 501,-1));
        return solve(s,0,0,dp);
    }
};