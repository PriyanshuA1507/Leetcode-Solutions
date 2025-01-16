class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
        int n = days.size();
        if (index >= n) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

    
        int o = costs[0] + solve(days, costs, index + 1, dp);

        int s = INT_MAX;
        int i = index;
        while (i < n && days[i] < days[index] + 7) {
            i++;
        }
        s = costs[1] + solve(days, costs, i, dp);


        int t = INT_MAX;
        i = index;
        while (i < n && days[i] < days[index] + 30) {
            i++;
        }
        t = costs[2] + solve(days, costs, i, dp);

    
        return dp[index] = min({o, s, t});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1); // Correct size of dp array
        return solve(days, costs, 0, dp);
    }
};
