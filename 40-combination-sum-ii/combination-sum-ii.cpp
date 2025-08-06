class Solution {
public:
    void solve(vector<int>& c, int target, vector<int>& a, vector<vector<int>>& ans, int index) {
        if (target == 0) {
            ans.push_back(a);
            return;
        }
        if (target < 0) return;

        for (int i = index; i < c.size(); i++) {
    
            if (i > index && c[i] == c[i - 1]) continue;

            if (c[i] > target) break;

            a.push_back(c[i]);
            solve(c, target - c[i], a, ans, i + 1);  
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());  
        vector<int> a;
        vector<vector<int>> ans;
        solve(c, target, a, ans, 0);
        return ans;
    }
};
