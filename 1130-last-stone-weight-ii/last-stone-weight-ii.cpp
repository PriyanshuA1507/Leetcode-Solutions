class Solution {
public:
    int solve(vector<int>& stones, int index, int current_sum, int total_sum, vector<vector<int>>& dp) {
        if (index >= stones.size()) {
            int other_sum = total_sum - current_sum;
            return abs(current_sum - other_sum);
        }
        if (dp[index][current_sum] != -1) {
            return dp[index][current_sum];
        }
        int include_in_current = solve(stones, index + 1, current_sum + stones[index], total_sum, dp);
        int exclude_from_current = solve(stones, index + 1, current_sum, total_sum, dp);
        return dp[index][current_sum] = min(include_in_current, exclude_from_current);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int total_sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(total_sum + 1, -1));
        return solve(stones, 0, 0, total_sum, dp);
    }
};
