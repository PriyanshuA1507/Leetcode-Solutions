class Solution {
public:
 int solve(int i,int j,bool diff,string s,string t,vector<vector<vector<int>>>&dp){
    if(i==s.size()|| j==t.size()){
        return 0;
    }
    if(dp[i][j][diff]!=-1){
        return dp[i][j][diff];
    }
    if(diff){
      if(s[i]!=t[j]){
        return dp[i][j][diff]=0;
      } 
      return dp[i][j][diff]=1 + solve(i+1,j+1,diff,s,t,dp);
    }
    if(s[i]!=t[j]){
        return dp[i][j][diff]= 1 + solve(i+1,j+1,true,s,t,dp);
    }
    return dp[i][j][diff]=solve(i+1,j+1,diff,s,t,dp);
 }
    int countSubstrings(string s, string t) {
    int ans =0;
    vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(t.size(),vector<int>(2,-1)));
     for(int i=0;i<s.size();i++){
    for(int j=0;j<t.size();j++){
       ans +=solve(i,j,false,s,t,dp);
    }
     }
     return ans;   
    }
};