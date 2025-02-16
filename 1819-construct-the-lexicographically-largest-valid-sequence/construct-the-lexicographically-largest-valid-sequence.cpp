class Solution {
public:
    bool solve(int index, int n, vector<int>& ans, vector<bool>& used) {
        if (index >= ans.size()) { // Base case: filled all positions
            return true;
        }
        if (ans[index] != -1) { // Skip if already filled
            return solve(index + 1, n, ans, used);
        }
        
        for (int num = n; num > 0; num--) { // Try numbers from n to 1
            if (used[num]) continue;

            int j = index + num; // Second position for the number
            
            if (num == 1 || (j < ans.size() && ans[j] == -1)) { // Place 1 only once, others need a second slot
                ans[index] = num;
                if (num > 1) ans[j] = num;
                used[num] = true;

                if (solve(index + 1, n, ans, used)) return true;

                // Backtrack
                ans[index] = -1;
                if (num > 1) ans[j] = -1;
                used[num] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1);
        vector<bool> used(n + 1, false);
        solve(0, n, ans, used);
        return ans;
    }
};
