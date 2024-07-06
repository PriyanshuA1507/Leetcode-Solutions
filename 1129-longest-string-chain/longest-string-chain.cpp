class Solution {
public:
     int solve(vector<string>& words,int ci,int pi,vector<vector<int>>& dp){
        if(ci>=words.size()){
            return 0;
        }
        if(dp[ci][pi+1]!=-1){
            return dp[ci][pi+1];
        }
        int take = 0;
        if(pi==-1){
        take = 1 + solve(words,ci+1,ci,dp);
        }
        else if(words[ci].size()==words[pi].size()+1){
         int i=0;
         int j =0 ;
         for( i=0;i<words[ci].size();i++){
            if(words[ci][i]==words[pi][j]){
                j++;
            }
         }
         if(j==words[pi].size()){
            take = 1 + solve(words,ci+1,ci,dp);
         }
        }
        int nottake = solve(words,ci+1,pi,dp);
        return dp[ci][pi+1]= max(take,nottake);
     }
    int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
       vector<vector<int>> dp(words.size()+1,vector<int>(words.size()+1,-1));
       return solve(words,0,-1,dp);
    }
};