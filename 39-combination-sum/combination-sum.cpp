class Solution {
public:
    int solve(vector<int>& candidates, int index, int target, vector<int>& curr, set<vector<int>>& ans) {
        if (target == 0) {
            ans.insert(curr);
            return 1;
        }
        if (target < 0 || index == candidates.size()) {
            return 0;
        }
        
        int take = 0;
        curr.push_back(candidates[index]);
        take = solve(candidates, index, target - candidates[index], curr, ans);
        curr.pop_back();
        
        int nottake = solve(candidates, index + 1, target, curr, ans);
        
        return take + nottake;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        set<vector<int>> ans;
        solve(candidates, 0, target, curr, ans);
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
