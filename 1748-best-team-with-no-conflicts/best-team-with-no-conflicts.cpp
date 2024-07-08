class Solution {
public:
    int solve(vector<pair<int,int>>& a,int index,int pi,vector<vector<int>>& dp){
        if(index>=a.size()){
            return 0;
        }
        if(dp[index][pi+1]!=-1){
            return dp[index][pi+1];
        }
        int take = 0;
        if(pi==-1 || a[pi].second<=a[index].second){
         take = a[index].second + solve(a,index+1,index,dp);
        }
        int nottake = solve(a,index+1,pi,dp);
        return dp[index][pi+1]=max(take,nottake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> a;
        for(int i=0;i<ages.size();i++){
            a.push_back({ages[i],scores[i]});
        }
        sort(a.begin(),a.end());
        vector<vector<int>> dp(a.size()+1,vector<int>(a.size()+1,-1));
        return solve(a,0,-1,dp);
    }
};