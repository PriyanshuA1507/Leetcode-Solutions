class Solution {
public:
  
    int solve(string word1, string word2,int a,int b,vector<vector<int>>& dp){
        if(a>=word1.size()){
            return (word2.size()-b);
        }
        else if(b>=word2.size()){
            return (word1.size()-a);
        }
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        int ans = 0;
        if(word1[a]==word2[b]){
            return dp[a][b]= solve(word1,word2,a+1,b+1,dp);
        }
        else{
            return dp[a][b] = min(1+solve(word1,word2,a+1,b,dp),1+solve(word1,word2,a,b+1,dp));
        }
        return 0;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(),n2= word2.size();
          vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};