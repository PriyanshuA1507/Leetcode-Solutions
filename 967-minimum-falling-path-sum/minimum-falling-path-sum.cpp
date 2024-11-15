class Solution {
public:
    int solve(vector<vector<int>>& matrix,int sr,int sc, vector<vector<int>>& dp){
    int row = matrix.size();
    int col = matrix[0].size();
    if(sr==row-1 && sc>=0 &&sc<col){
      return matrix[sr][sc];
    }
    if(sr>=row || sc>=col || sc<0){
        return 1e9;
    }
    if(dp[sr][sc]!=INT_MAX){
        return dp[sr][sc];
    }
    int o1 = matrix[sr][sc] + solve(matrix,sr+1,sc-1,dp);
    int o2 = matrix[sr][sc] + solve(matrix,sr+1,sc,dp);
    int o3 = matrix[sr][sc] + solve(matrix,sr+1,sc+1,dp);
    return dp[sr][sc]=min({o1,o2,o3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        int ans = INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
        ans = min(ans,solve(matrix,0,i,dp));
        }
        return ans;
    }
};