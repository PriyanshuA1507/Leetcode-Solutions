class Solution {
public:
   bool ispalin(int i,int j,string& s){
    while(i<j){
    if(s[i]!=s[j]){
        return false;
    }
    i++;
    j--;
    }
    return true;
   }
   int mp(string& s,int start,int n, vector<int>& dp){
    if(start>=n){
        return 0;
    }
    if(dp[start]!=-1){
        return dp[start];
    }
    int mc = 1e8;
    for(int i=start;i<n;i++){
     if(ispalin(start,i,s)){
     int cost = 1 + mp(s,i+1,n,dp);
     mc = min(cost,mc);
     }
    }
    return dp[start]=mc;
   }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
    return mp(s,0,s.size(),dp)-1;
    }
};