class Solution {
public:
int const mod = 1000000007;
    int solve(vector<int>& locations, int start, int finish, int fuel,vector<vector<int>>& dp){
        int n = locations.size();
        if(fuel<0){
            return 0;
        }
        if(dp[start][fuel]!=-1){
            return dp[start][fuel];
        }
        int ans = 0;
        if(start==finish){
            ans=1;
        }
        for(int i=0;i<n;i++){
        if(i!=start){
            ans= (ans%mod)+(solve(locations,i,finish,fuel-abs(locations[i]-locations[start]),dp)%mod);
        }
        }
        return dp[start][fuel]=ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
         int n = locations.size();
        vector<vector<int>> dp(n+1,vector<int>(201,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};