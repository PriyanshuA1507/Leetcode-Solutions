class Solution {
public:

bool check(vector<int>base, vector<int> newbox){
if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2])
return true;

else 
return false;

}

int solve(int n, vector<vector<int>>& a,int ci, int pi,vector<vector<int>>& dp){
if(ci==n){
    return 0;
}
if(dp[ci][pi+1]!=-1){
    return dp[ci][pi+1];
}
int take = 0;
if(pi == -1 || check(a[ci],a[pi])){
take += a[ci][2] + solve(n,a,ci+1,ci,dp);
}
int nottake = solve(n,a,ci+1,pi,dp);
return dp[ci][pi+1]= max(take,nottake);

}
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
  //step1: sort all dimensions for every cuboid
  for(auto &a: cuboids){
      sort(a.begin(),a.end());
  }
 // step2: sort all cuboids basis on w and l
 sort(cuboids.begin(),cuboids.end());
 // step3; use lis logic
 return solve(cuboids.size(),cuboids,0,-1,dp);     
    }
};