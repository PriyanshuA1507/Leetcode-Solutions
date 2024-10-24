class Solution {
public:
     int solve(vector<int>& nums,int index,vector<int>& dp){
    if(index>=nums.size()){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int take = nums[index] + solve(nums,index+2,dp);
    int nottake = solve(nums,index+1,dp);
    return dp[index]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n  = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> a,b;
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        for(int i=0;i<nums.size()-1;i++){
            a.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++){
            b.push_back(nums[i]);
        }
        return max(solve(a,0,dp1), solve(b,0,dp2));
    }
};