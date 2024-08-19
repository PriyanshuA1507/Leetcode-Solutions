class Solution {
public:
    int solve(vector<int>& piles, int p, int index, int M, vector<vector<vector<int>>>& memo) {
        int n = piles.size();
        if (index >= n) return 0;
        if (memo[p][index][M] != -1) return memo[p][index][M];

        int stones = 0;
        int result;

        if (p == 1) {
            result = INT_MIN;
            for (int x = 1; x <= 2 * M && index + x <= n; ++x) {
                stones += piles[index + x - 1];
                result = max(result, stones + solve(piles, 0, index + x, max(M, x), memo));
            }
        } else {
            result = INT_MAX;
            for (int x = 1; x <= 2 * M && index + x <= n; ++x) {
                result = min(result, solve(piles, 1, index + x, max(M, x), memo));
            }
        }

        memo[p][index][M] = result;
        return result;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> memo(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return solve(piles, 1, 0, 1, memo);
    }
};
