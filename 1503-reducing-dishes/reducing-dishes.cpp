class Solution {
public:
    int solve(vector<int>& s,int index,int time, vector<vector<int>>& dp){
        if(index>=s.size()){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        int take = s[index]*time + solve(s,index+1,time+1,dp);
        int nottake = solve(s,index+1,time,dp);
        return dp[index][time]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        vector<vector<int>> dp(500,vector<int>(n+1,-1));
        sort(s.begin(),s.end());
        return solve(s,0,1,dp);
    }
};