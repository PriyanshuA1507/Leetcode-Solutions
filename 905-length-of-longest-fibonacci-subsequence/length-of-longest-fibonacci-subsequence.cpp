class Solution {
public:
     int solve(vector<int>& arr,int index1,int index2,vector<vector<int>>& dp,unordered_map<int, int>& mp){
        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        int take = 0;
        int nextVal = arr[index1] + arr[index2];

        if (mp.count(nextVal)) { 
            int nextIndex = mp[nextVal];
            if (nextIndex > index2) { 
                take = 1 + solve(arr, index2, nextIndex, dp, mp);
            }
        }

        return dp[index1][index2] = take;
     }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
       vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = 0;
         unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;  
        }
        for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
        if(solve(arr,i,j,dp,mp)>0){
         ans = max(ans, 2 + solve(arr,i,j,dp,mp));
        }
        }
        }
        return ans;
    }
};
