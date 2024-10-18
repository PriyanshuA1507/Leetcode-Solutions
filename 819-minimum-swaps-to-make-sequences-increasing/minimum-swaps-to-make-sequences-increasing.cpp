class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped,vector<vector<int>>& dp){
     if(index==nums1.size()){
        return 0;
     }
     int prev1 = nums1[index-1];
     int prev2 = nums2[index-1];
     if(swapped){
     swap(prev1,prev2);
     }
     if(dp[index][swapped]!=-1){
        return dp[index][swapped];
     }
    int swap = INT_MAX, noswap= INT_MAX;
    if(prev1<nums1[index] && prev2<nums2[index]){
     noswap = solve(nums1,nums2,index+1,false,dp);
    }
     if(prev1<nums2[index] && prev2<nums1[index]){
     swap = 1 + solve(nums1,nums2,index+1,true,dp);
    }
    return dp[index][swapped]=min(swap,noswap);

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    vector<vector<int>> dp(nums1.size()+1,vector<int>(3,-1));
     return solve(nums1,nums2,1,false,dp);   
    }
};