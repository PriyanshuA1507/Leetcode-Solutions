class Solution {
public:
    using ll = long long;
    ll n, dp[(ll)1e5 + 5][4][4];
    vector<int> colorMapping = {1, 2, 3};

    ll solve(int i, int prev1, int prev2, int n, vector<vector<int>>& cost) {
        if (i >= n / 2) return 0;

        if (dp[i][prev1][prev2] != -1) return dp[i][prev1][prev2];

        ll result = LLONG_MAX;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (colorMapping[j] != colorMapping[k] && colorMapping[j] != prev1 && colorMapping[k] != prev2) {
                    result = min(result, 
                        cost[i][colorMapping[j] - 1] + 
                        cost[n - i - 1][colorMapping[k] - 1] + 
                        solve(i + 1, colorMapping[j], colorMapping[k], n, cost));
                }
            }
        }
        return dp[i][prev1][prev2] = result;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        this->n = n;
        for (int i = 0; i <= n / 2; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(0, 0, 0, n, cost);
    }
};
