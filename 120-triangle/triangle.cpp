class Solution {
public:
   int solve(vector<vector<int>>& triangle,int index,int ci,vector<vector<int>>& dp){
    if(index>=triangle.size()){
        return 0;
    }
    if(dp[index][ci]!=-1){
        return dp[index][ci];
    }
    int o1 = INT_MAX, o2 = INT_MAX;
    if(ci<triangle[index].size()){
    o1  = triangle[index][ci] + solve(triangle,index+1,ci,dp);
    }
    if(ci+1<triangle[index].size()){
    o2  = triangle[index][ci+1] + solve(triangle,index+1,ci+1,dp);
    }
    return dp[index][ci]=min(o1,o2);
   }
    int minimumTotal(vector<vector<int>>& triangle) {
       vector<vector<int>> dp(201, vector<int>(201,-1));
        return solve(triangle,0,0,dp);
        
    }
};