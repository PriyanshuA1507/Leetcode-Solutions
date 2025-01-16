class Solution {
public:
    int solve(vector<int>& arr, int k,int index,vector<int>& dp){
        if(index>=arr.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans = -1e8;
        int maxi = 0;
        for(int i=0;i<k && index+i<arr.size();i++){
         maxi  = max(maxi,arr[index+i]);
         ans = max(ans, (i+1)*(maxi)+ solve(arr,k,index+i+1,dp));
        }
        return dp[index]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve(arr,k,0,dp);
    }
};