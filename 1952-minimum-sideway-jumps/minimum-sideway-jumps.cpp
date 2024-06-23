class Solution {
public:
   int solve(int index,vector<int>& obstacles,int lane,vector<vector<int>>& dp){
    if(index==obstacles.size()-1){
        return 0;
    }
    if(dp[index][lane]!=-1){
        return dp[index][lane];
    }
    if(obstacles[index+1]!=lane){
     return solve(index+1,obstacles,lane,dp);
    }
    int ans = INT_MAX;
    for(int i=1;i<=3;i++){
        if(lane!= i && obstacles[index]!=i){
            ans = min(ans,  1+solve(index,obstacles,i,dp));
        }
    }
     dp[index][lane] = ans;
     return dp[index][lane];
   }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
     vector<vector<int>> dp(n,vector<int>(4,-1));
     return solve(0,obstacles,2,dp);
    }
};
