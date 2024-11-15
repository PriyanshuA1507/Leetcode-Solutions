class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j,vector<vector<int>>& dp) {
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        if (i >= triangle.size() || j >= triangle[i].size()) {
            return INT_MAX; 
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int option1 = triangle[i][j] + solve(triangle, i + 1, j,dp);
        int option2 = triangle[i][j] + solve(triangle, i + 1, j + 1,dp);

        return dp[i][j]=min(option1, option2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        return solve(triangle, 0, 0,dp); 
    }
};
