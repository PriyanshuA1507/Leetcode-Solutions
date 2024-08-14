class Solution {
public:
    bool c(string& a, string& b) {
        if (b.size() - a.size() != 1) return false;
        unordered_map<char,int> m;
          int i = 0, j = 0;
        while (j < b.size()) {
            if (i < a.size() && a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.size();  
    }

    
    int solve(vector<string>& words, int index, int pi, vector<vector<int>>& dp) {
        if (index >= words.size()) {
            return 0;
        }

        if (dp[index][pi + 1] != -1) {
            return dp[index][pi + 1];
        }

        int include = 0;
        if (pi == -1 || c(words[pi], words[index])) {
            include = 1 + solve(words, index + 1, index, dp);
        }

        int exclude = solve(words, index + 1, pi, dp);

        dp[index][pi + 1] = max(include, exclude);
        return dp[index][pi + 1];
    }

    // Main function to return the length of the longest string chain
    int longestStrChain(vector<string>& words) {
        // Sort words by their length (ascending)
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));  // Memoization table

        return solve(words, 0, -1, dp);
    }
};
