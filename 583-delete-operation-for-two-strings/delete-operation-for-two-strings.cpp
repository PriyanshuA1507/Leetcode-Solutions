class Solution {
public:
    int solve(string word1, string word2,int index1,int index2,vector<vector<int>>& dp){
        if(index1>=word1.size() && index2<word2.size()){
            return word2.size()-index2;
        }
        if(index2>=word2.size() && index1<word1.size()){
            return word1.size()-index1;
        }
        if(index1>=word1.size() && index2>=word2.size()){
            return 0;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
                    }
        if(word1[index1]==word2[index2]){
        return solve(word1,word2,index1+1,index2+1,dp);
        }
        int o1 = 1+solve(word1,word2,index1+1,index2,dp);
        int o2 = 1+solve(word1,word2,index1,index2+1,dp);

        return dp[index1][index2]=min(o1,o2);
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
      return solve(word1,word2,0,0,dp);  
    }
};