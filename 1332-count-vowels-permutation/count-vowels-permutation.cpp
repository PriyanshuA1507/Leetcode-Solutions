class Solution {
public:
    const int mod = 1e9 + 7;

    long long solve(int n, int index, char pc, vector<vector<long long>>& dp) {
        if (index >= n) return 1;  

        int c = (pc == 'a') ? 0 : 
                (pc == 'e') ? 1 : 
                (pc == 'i') ? 2 : 
                (pc == 'o') ? 3 : 
                (pc == 'u') ? 4 : -1;

        if (c != -1 && dp[index][c] != -1) return dp[index][c];

        long long take = 0; 

        if (pc == 'b') {  
            take = (solve(n, index + 1, 'a', dp) +
                    solve(n, index + 1, 'e', dp) +
                    solve(n, index + 1, 'i', dp) +
                    solve(n, index + 1, 'o', dp) +
                    solve(n, index + 1, 'u', dp)) % mod;
            return take; 
        }
        else if (pc == 'a') {
            take = solve(n, index + 1, 'e', dp);
        }
        else if (pc == 'e') {
            take = (solve(n, index + 1, 'a', dp) + solve(n, index + 1, 'i', dp)) % mod;
        }
        else if (pc == 'i') {
            take = (solve(n, index + 1, 'a', dp) + solve(n, index + 1, 'e', dp) +
                    solve(n, index + 1, 'o', dp) + solve(n, index + 1, 'u', dp)) % mod;
        }
        else if (pc == 'o') {
            take = (solve(n, index + 1, 'i', dp) + solve(n, index + 1, 'u', dp)) % mod;
        }
        else if (pc == 'u') {
            take = solve(n, index + 1, 'a', dp);
        }

        return dp[index][c] = take % mod; 
    }

    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(5, -1)); 
        return solve(n, 0, 'b', dp);
    }
};
