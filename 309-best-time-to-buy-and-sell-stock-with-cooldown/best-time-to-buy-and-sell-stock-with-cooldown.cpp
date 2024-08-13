class Solution {
public:
    int solve(int index, int buy, std::vector<int>& prices, std::vector<std::vector<int>>& dp) {
        if (index >= prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        if (buy) {
            int buykaro = -prices[index] + solve(index + 1, 0, prices, dp);
            int skipkaro = solve(index + 1, 1, prices, dp);
            profit = std::max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solve(index + 2, 1, prices, dp);
            int skipkaro = solve(index + 1, 0, prices, dp);
            profit = std::max(sellkaro, skipkaro);
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, -1)); // Adjusted dimensions to [n][2]
        return solve(0, 1, prices, dp);
    }
};