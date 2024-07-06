class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index1,int index2,vector<vector<int>>& dp){
        if(index1>=nums1.size()|| index2>=nums2.size()){
            return 0;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        if(nums1[index1]==nums2[index2]){
        return dp[index1][index2]= 1 + solve(nums1,nums2,index1+1,index2+1,dp);
        }
        else{
            return dp[index1][index2]= max(solve(nums1,nums2,index1+1,index2,dp),solve(nums1,nums2,index1,index2+1,dp));
        }
        return 0;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return solve(nums1,nums2,0,0,dp);
    }
};