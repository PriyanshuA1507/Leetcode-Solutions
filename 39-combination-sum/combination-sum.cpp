class Solution {
public:
    void solve(vector<int>& candidates, int target,int index, vector<int> curr,vector<vector<int>>& ans){
    if(index>=candidates.size()){
    if(target==0){
    ans.push_back(curr);
    }
    return;
    }

    if(target<0){
        return;
    }
    
      curr.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index, curr, ans);
        curr.pop_back();  


        solve(candidates, target, index + 1, curr, ans);
   
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<int> curr;
      vector<vector<int>> ans;
        solve(candidates,target,0,curr,ans);
        return ans;
    }
};