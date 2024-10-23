class Solution {
public:
    // Memoization map to store intermediate results
    unordered_map<int, int> memo;

    bool check(const string& a, const string& b) {
        if (b.size() + 1 != a.size()) {
            return false;
        }
        int i = 0, j = 0;
        while (i < a.size()) {
            if (a[i] == b[j]) {
                j++;
            }
            i++;
            if (j == b.size()) break;
        }
        return j == b.size();
    }

    int solve(vector<string>& words, int ci, int pi) {
        if (ci >= words.size()) {
            return 0;
        }
        // Memoization key based on current and previous indices
        int key = ci * 1000 + pi;
        if (memo.count(key)) return memo[key];

        int take = 0;
        if (pi == -1 || check(words[ci], words[pi])) {
            take = 1 + solve(words, ci + 1, ci);
        }

        int nottake = solve(words, ci + 1, pi);
        return memo[key] = max(take, nottake);
    }

    int longestStrChain(vector<string>& words) {
        // Sort words by length
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        // Clear the memo map before solving
        memo.clear();
        return solve(words, 0, -1);
    }
};
