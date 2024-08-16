class Solution {
public:
    bool solve(vector<int>& nums, int index,vector<int>& dp) {
        if (index >= nums.size() - 1) {
            return true;  
        }
        if(dp[index]!=-1){
            return dp[index];
        }

        int maxJump = nums[index];
        for (int i = 1; i <= maxJump; i++) {
            if (solve(nums, index + i,dp)) {
                return true;  
            }
        }

        return dp[index]=false;  
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums, 0,dp);
    }
};
