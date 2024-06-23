class Solution {
public:
    // Recursive function with memoization to solve the problem
    int solve(int index, int ei, vector<int>& slices, int a, vector<vector<int>>& dp) {
        // Base cases
        if (a == 0 || index > ei) {
            return 0;
        }
        // Check if the result is already computed
        if (dp[index][a] != -1) {
            return dp[index][a];
        }
        // Recursive cases: take or not take the current slice
        int take = slices[index] + solve(index + 2, ei, slices, a - 1, dp);
        int nottake = 0 + solve(index + 1, ei, slices, a, dp);
        // Store the result in dp and return the maximum of both cases
        return dp[index][a] = max(take, nottake);
    }

    // Main function to solve the problem
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int>(k / 3 + 1, -1));
         vector<vector<int>> dp2(k, vector<int>(k / 3 + 1, -1));
        // Consider two cases to handle the circular array nature
        int case1 = solve(0, k - 2, slices, k / 3, dp1);
        int case2 = solve(1, k - 1, slices, k / 3, dp2);
        // Return the maximum of both cases
        return max(case1, case2);
    }
};
