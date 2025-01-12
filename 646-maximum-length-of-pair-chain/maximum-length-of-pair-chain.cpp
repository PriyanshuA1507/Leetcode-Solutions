class Solution {
public:
    int solve(vector<vector<int>>& pairs,int index,int a, vector<int>& dp){
    if(index>=pairs.size()){
        return 0;
    }
    int take = 0;
    if(dp[index]!=-1){
        return dp[index];
    }
    if(pairs[index][0]>a){
     take = 1 + solve(pairs,index+1,pairs[index][1],dp);
    }
    int nottake = solve(pairs,index+1,a,dp);

    return dp[index]=max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

     int n = pairs.size();
     vector<int> dp(n+1,-1);
     return solve(pairs,0,INT_MIN,dp);   
    }
};