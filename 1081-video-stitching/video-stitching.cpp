class Solution {
public:
    int solve(vector<vector<int>>& clips, int time,int index,int end,vector<vector<int>>& dp){
     if(end>=time){
        return 0;
    }
    if(index>=clips.size()){
        return 1e8;
    }
    if(dp[index][end]!=-1){
        return dp[index][end];
    }
    int take = 1e8,nottake = 1e8;
    if(clips[index][0]<=end){
    take = 1 + solve(clips,time,index+1,max(end,clips[index][1]),dp);
    }
     nottake = solve(clips,time,index+1,end,dp);

    return dp[index][end]=min(take,nottake);
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        sort(clips.begin(),clips.end());
     vector<vector<int>> dp(n+1,vector<int>(time+1,-1));
     int ans= solve(clips,time,0,0,dp);   
     return (ans >= 1e8) ? -1 : ans;
    }
};