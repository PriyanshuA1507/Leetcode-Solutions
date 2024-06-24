class Solution {
public:
    
    int solve(int i, int d, vector<int>& nums, vector<vector<int>>& dp) {
        if (i < 0) {
            return 0;
        }
        
      
        int offset = 500;  
        if (dp[i][d + offset] != -1) {
            return dp[i][d + offset];
        }
        
        int ans = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] - nums[j] == d) {
                ans = max(ans, 1 + solve(j, d, nums, dp));
            }
        }
        
        dp[i][d + offset] = ans;
        return ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        
        int ans = 0;
        int offset = 500; 
        vector<vector<int>> dp(n, vector<int>(1001, -1));  
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                ans = max(ans, 2 + solve(i, diff, nums, dp));
            }
        }
        
        return ans;
    }
};
