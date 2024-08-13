class Solution {
public:
    int solve(string word1, string word2,int i,int j,vector<vector<int>>& dp){
        if(i==word1.size()){
            return word2.size()-j;
        }
        if(j==word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return solve(word1,word2,i+1,j+1,dp);
        }
        int insert = 1 + solve(word1,word2,i,j+1,dp);
        int delet = 1 + solve(word1,word2,i+1,j,dp);
        int replace = 1 + solve(word1,word2,i+1,j+1,dp);

        return dp[i][j]=min({insert,delet,replace});
    }
    int minDistance(string word1, string word2) {
        int n = max(word1.size(),word2.size());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
      return solve(word1,word2,0,0,dp);  
    }
};