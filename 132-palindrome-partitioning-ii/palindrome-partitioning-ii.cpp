class Solution {
public:
    bool isp(int i,int j,string& s){
    while(i<j){
    if(s[i]!=s[j]) return false;
    i++;
    j--;
    }
    return true;
    }
    int solve(string& s,int start,int end,vector<int>& dp){
     if(start>=end){
        return 0;
     }
     if(dp[start]!=-1){
        return dp[start];
     }
     int mc = 1e8;
     for(int i=start;i<end;i++){
     if(isp(start,i,s)){
    int cost = 1 + solve(s,i+1,end,dp);
    mc = min(mc,cost);
     }
     }
     return dp[start]=mc;
    }
    int minCut(string s) {
    int n = s.size();
    vector<int> dp(n,-1);
    return solve(s,0,s.size(),dp)-1;
    }
};