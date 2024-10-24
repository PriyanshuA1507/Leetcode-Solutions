class Solution {
public:
    int solve (vector<vector<int>>& obstacleGrid,int si,int sj,int n,int m,vector<vector<int>>& dp){
     if(si==n-1 && sj==m-1 && obstacleGrid[si][sj]==0){
        return 1;
     }
     if(si>=n || sj>=m || obstacleGrid[si][sj] == 1){
        return 0;
     }
     if(dp[si][sj]!=-1){
        return dp[si][sj];
     }
     int down = 0;
     if( si+1<n && obstacleGrid[si+1][sj]!=1 ){
    down =solve(obstacleGrid,si+1,sj,n,m,dp);
     }
     int right = 0;
      if(sj+1<m && obstacleGrid[si][sj+1]!=1 ){
     right = solve(obstacleGrid,si,sj+1,n,m,dp);
      }
     return dp[si][sj]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(obstacleGrid,0,0,n,m,dp);
    }
};