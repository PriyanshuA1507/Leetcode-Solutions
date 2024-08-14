class Solution {
public:
    int solve(vector<int>& candidates, int target, int index, vector<int>& curr, set<vector<int>>& ans) {
        if (target == 0) {
            ans.insert(curr);
            return 1;
        }
        if (index >= candidates.size() || target < 0) {
            return 0;
        }
        int take = 0;

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            take += solve(candidates, target - candidates[i], i + 1, curr, ans); 
            curr.pop_back();
        }

        return take;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        set<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, curr, ans);
        vector<vector<int>> a(ans.begin(), ans.end());
        return a;
    }
};
