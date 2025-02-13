class Solution {
public:
   int z(string s){
    int z=0;
    for(auto a:s){
        if(a=='0'){
        z++;
        }
    }
    return z;
   }
      int o(string s){
    int z=0;
    for(auto a:s){
        if(a=='1'){
        z++;
        }
    }
    return z;
   }
    int solve(vector<string>& strs, int m, int n,int index,vector<vector<vector<int>>>& dp){
     if(index>=strs.size()){
        return 0;
     }
    if(m<0 || n<0){
        return INT_MAX;
    }
    if(m==0 && n==0){
        return 0;
    }
    if(dp[m][n][index]!=-1){
        return dp[m][n][index];
    }
    int take =0;
    if(z(strs[index])<=m && o(strs[index])<=n){
    take= 1 + solve(strs,m-z(strs[index]),n-o(strs[index]),index+1,dp);
    }
    int nottake = solve(strs,m,n,index+1,dp);

    return dp[m][n][index]=max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(s+1,-1)));
       return solve(strs,m,n,0,dp);
    }
};