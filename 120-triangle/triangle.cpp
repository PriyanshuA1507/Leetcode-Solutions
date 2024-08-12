class Solution {
public:
      int solve(vector<vector<int>>& triangle, int si ,int sj ,int n,int m,vector<vector<int>>& dp){
        if(si==n-1){
            return triangle[si][sj];
        }
        if(dp[si][sj]!=-1){
            return dp[si][sj];
        }
       int down = solve(triangle,si+1,sj,n,m,dp);
      int diagonal = solve(triangle,si+1,sj+1,n,m,dp);

        return dp[si][sj]= triangle[si][sj] + min(down,diagonal);
      }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
       return solve(triangle,0,0,n,m,dp);
    }
};