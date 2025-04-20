class Solution {
public:
    int solve(vector<int>& cuts, int start, int end, vector<vector<int>>& dp) {
        if (end - start <= 1) {
            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        long long ans = LLONG_MAX;

        for (int k = start + 1; k < end; ++k) {
            long long cost = cuts[end] - cuts[start];
            long long totalCost = cost + solve(cuts, start, k, dp) + solve(cuts, k, end, dp);
            ans = min(ans, totalCost);
        }

        return dp[start][end] = static_cast<int>(ans);
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);  
        cuts.push_back(n);

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(cuts, 0, m - 1, dp);   
    }
};
