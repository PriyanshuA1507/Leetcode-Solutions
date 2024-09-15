class Solution {
public:
    int solve(vector<int>& cuts, int start, int end, vector<vector<int>>& dp) {
        if (end - start == 1) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        
        int result = INT_MAX;
        for (int index = start + 1; index < end; index++) {
            int cost = solve(cuts, start, index, dp) + solve(cuts, index, end, dp) + (cuts[end] - cuts[start]);
            result = min(result, cost);
        }
        
        return dp[start][end] = result;
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
