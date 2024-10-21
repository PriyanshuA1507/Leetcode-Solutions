class Solution {
public:
    // Memoized function to find the minimum edit distance
    int solve(string& word1, string& word2, int index1, int index2, vector<vector<int>>& dp) {
        if (index1 == word1.size()) {
            return word2.size() - index2; // Insert remaining characters from word2
        }
        if (index2 == word2.size()) {
            return word1.size() - index1; // Delete remaining characters from word1
        }
        
        // If already computed, return the stored value
        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        // If characters match, move to the next characters
        if (word1[index1] == word2[index2]) {
            return dp[index1][index2] = solve(word1, word2, index1 + 1, index2 + 1, dp);
        }
        
        // Perform insert, delete, and replace operations
        int insert = 1 + solve(word1, word2, index1, index2 + 1, dp);     // Insert character
        int delet = 1 + solve(word1, word2, index1 + 1, index2, dp);      // Delete character
        int replace = 1 + solve(word1, word2, index1 + 1, index2 + 1, dp); // Replace character

        // Store and return the minimum cost of the three operations
        return dp[index1][index2] = min({insert, delet, replace});
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        // Initialize a dp table to store the results of subproblems
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
