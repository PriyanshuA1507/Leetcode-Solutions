class Solution {
public:
    int solve(vector<pair<int, int>>& a, int index, int last_index, vector<vector<int>>& dp) {
        if (index >= a.size()) {
            return 0;
        }
        if (dp[index][last_index + 1] != -1) {
            return dp[index][last_index + 1];
        }
        int take = 0;
        if (last_index == -1 || a[last_index].second <= a[index].second) {
            take = a[index].second + solve(a, index + 1, index, dp);
        }
        int nottake = solve(a, index + 1, last_index, dp);
        return dp[index][last_index + 1] = max(take, nottake);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> a;
        for (int i = 0; i < ages.size(); i++) {
            a.push_back({ages[i], scores[i]});
        }
        sort(a.begin(), a.end());
        vector<vector<int>> dp(a.size(), vector<int>(a.size() + 1, -1));
        return solve(a, 0, -1, dp);
    }
};
