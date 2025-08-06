class Solution {
public:
    void solve(vector<int>& c,int target,vector<int> a,vector<vector<int>>& ans,int index){
    if(target==0){
    ans.push_back(a);
    return;
    }
    if (index == c.size() || target < 0) return;

    if(c[index]<=target){
    a.push_back(c[index]);
    solve(c,target - c[index],a,ans,index);
     a.pop_back();
    }
    
    solve(c,target,a,ans,index+1);

    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int> a;
        vector<vector<int>> ans;
        solve(c,target,a,ans,0);
        return ans;
    }
};