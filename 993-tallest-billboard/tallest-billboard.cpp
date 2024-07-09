class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;  

    int solve(vector<int>& rods, int index, int diff) {
        if (index == rods.size()) {
            return diff == 0 ? 0 : INT_MIN;
        }
        
        if (dp[index].find(diff) != dp[index].end()) {
            return dp[index][diff];
        }
        
        int include_in_left = solve(rods, index + 1, diff + rods[index]);
        int include_in_right = solve(rods, index + 1, diff - rods[index]);
        int exclude = solve(rods, index + 1, diff);
        
        int result = max({include_in_left, include_in_right + rods[index], exclude});
        dp[index][diff] = result;
        return result;
    }

    int tallestBillboard(vector<int>& rods) {
        dp.clear();
        int result = solve(rods, 0, 0);
        return result < 0 ? 0 : result;
    }
};