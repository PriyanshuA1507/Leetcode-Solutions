class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& memo) {
        if (n < 0) {
            return 0;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int incl = nums[n] + solve(nums, n - 2, memo);
        int excl = solve(nums, n - 1, memo);
        memo[n] = max(incl, excl);
        return memo[n];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> memo(n, -1);
        return solve(nums, n - 1, memo);
    }
};