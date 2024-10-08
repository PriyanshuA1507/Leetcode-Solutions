#include <vector>
#include <climits>

class Solution {
public:
    int solve(std::vector<int>& coins, int amount, std::vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = solve(coins, amount - coins[i], dp);
            if (ans != INT_MAX) {
                mini = std::min(mini, ans + 1);
            }
        }
        return dp[amount] = mini;
    }

    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans; 
    }
};
