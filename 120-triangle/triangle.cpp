class Solution {
public:
    int solve(vector<vector<int>>& triangle,int si,int sj,int n,vector<vector<int>>& dp){
    if(si==n-1 ){
        return triangle[si][sj];
    }
    if(dp[si][sj]!=-1){
        return dp[si][sj];
    }
    int one = INT_MAX, second = INT_MAX;
    if(si==0 || si+1<n ){
    one = triangle[si][sj] + solve(triangle,si+1,sj,n,dp);
    }
    if(si==0 || si+1<n ){
    second = triangle[si][sj] + solve(triangle,si+1,sj+1,n,dp);
    }
    return dp[si][sj]=min({one,second});
    }
    int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(triangle,0,0,n,dp);
    }
};