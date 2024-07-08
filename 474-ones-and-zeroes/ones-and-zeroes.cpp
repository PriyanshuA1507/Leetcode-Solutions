class Solution {
public:
     int solve(vector<string>& strs, int m, int n,int zc,int oc,int index,vector<vector<vector<int>>>&dp){
      if(index>=strs.size()){
        return 0;
      }
      if(zc>m && oc>0){
        return 0;
      }
      if(dp[zc][oc][index]!=-1){
        return dp[zc][oc][index];
      }
      int take = 0;
       int z=0,o=0;
      string c = strs[index];
      for(int i=0;i<c.size();i++){
         if(c[i]=='0'){
            z++;
         }
         else{
            o++;
         }
      }
      if(zc+z<=m && oc+o<=n){
      take = 1 + solve(strs,m,n,zc+z,oc+o,index+1,dp);
      }
      int nottake = solve(strs,m,n,zc,oc,index+1,dp);
      return dp[zc][oc][index]=max(take,nottake);
     }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int n1 = strs.size();
       vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(n1+ 1, -1)));
        return solve(strs,m,n,0,0,0,dp);
    }
};