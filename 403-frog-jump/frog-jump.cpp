class Solution {
public:
  unordered_map<int, int> stoneToIndex; 

    bool solve(vector<int>& stones, int index, int k, vector<vector<int>>& dp) {
        if (index == stones.size() - 1) return true;

        if (dp[index][k] != -1) return dp[index][k];

        for (int jump = k - 1; jump <= k + 1; ++jump) {
            if (jump <= 0) continue;

            int nextPos = stones[index] + jump;
            if (stoneToIndex.count(nextPos)) {
                int nextIndex = stoneToIndex[nextPos];
                if (solve(stones, nextIndex, jump, dp)) {
                    return dp[index][k] = 1;
                }
            }
        }

        return dp[index][k] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
    
        for (int i = 0; i < n; ++i) {
            stoneToIndex[stones[i]] = i;
        }

        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(stones, 0, 0, dp); 
    }
};