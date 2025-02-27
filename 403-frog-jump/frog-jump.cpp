class Solution {
public:
    unordered_map<int, int> m;
    bool solve(vector<int>& stones,int ci,int jumps,vector<vector<int>>& dp){
    if(ci==stones.size()-1){
        return true;
    }
    if(dp[ci][jumps]!=-1){
        return dp[ci][jumps];
    }
     bool a = false,b = false,c = false;
     if( m[stones[ci]+jumps]){
     a= solve(stones,m[stones[ci]+jumps],jumps,dp);
    }
    if(jumps>1 && m[stones[ci]+jumps-1]){
     b =  solve(stones,m[stones[ci]+jumps-1],jumps-1,dp);
    }
    if(m[stones[ci]+jumps+1]){
     c= solve(stones,m[stones[ci]+jumps+1],jumps+1,dp);
    }
    
    return dp[ci][jumps]=(a||b||c);
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int jumps = 0;
        for(auto a:stones){
         jumps = max(a,jumps);
        }
        vector<vector<int>> dp(n+1,vector<int>(2000+1,-1));
        if (stones[1] - stones[0] != 1) {
            return false;
        }
         for (int i = 0; i < stones.size(); i++) {
            m[stones[i]] = i;
        }
       return solve(stones,1,1,dp); 
    }
};