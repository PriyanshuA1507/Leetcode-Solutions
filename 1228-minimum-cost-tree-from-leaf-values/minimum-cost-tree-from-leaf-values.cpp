class Solution {
public:
    vector<vector<int>> dp;  

    int solve(vector<int>& arr, int start, int end) {
        if (start >= end) return 0; 
        
        if (dp[start][end] != -1) return dp[start][end]; 
        
        int ans = INT_MAX;
        for (int i = start; i < end; i++) {
            int leftCost = solve(arr, start, i);
            int rightCost = solve(arr, i + 1, end);
            int maxLeft = *max_element(arr.begin() + start, arr.begin() + i + 1);
            int maxRight = *max_element(arr.begin() + i + 1, arr.begin() + end + 1);
            
            int tempCost = leftCost + rightCost + maxLeft * maxRight;
            ans = min(ans, tempCost);
        }

        return dp[start][end] = ans; 
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(n, -1)); 
        return solve(arr, 0, n - 1); 
    }
};
