class Solution {
public:
    int solve(vector<vector<int>>& matrix, int sr, int sc, vector<vector<int>>& memo) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        if (sr == row - 1 && sc >= 0 && sc < col) {
            return matrix[sr][sc];
        }
        if (sr >= row || sc < 0 || sc >= col) {
            return 1e9;
        }
        if (memo[sr][sc] != INT_MAX) {
            return memo[sr][sc];
        }

        int o1 = matrix[sr][sc] + solve(matrix, sr + 1, sc - 1, memo);
        int o2 = matrix[sr][sc] + solve(matrix, sr + 1, sc, memo);
        int o3 = matrix[sr][sc] + solve(matrix, sr + 1, sc + 1, memo);

        return memo[sr][sc] = min({o1, o2, o3});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int col = matrix[0].size();
        vector<vector<int>> memo(matrix.size(), vector<int>(col, INT_MAX));

        for (int i = 0; i < col; i++) {
            ans = min(ans, solve(matrix, 0, i, memo));
        }
        return ans;
    }
};