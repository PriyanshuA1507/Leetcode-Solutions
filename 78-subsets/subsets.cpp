class Solution {
public:
     void subs(vector<int>& nums,vector<vector<int>>& ans){
      if(nums.size()==0){
        ans.push_back({});
        return;
      }
      int a = nums.back();
      nums.pop_back();
      subs(nums,ans);
             int currentSize = ans.size();
        for (int i = 0; i < currentSize; i++) {
            vector<int> subset = ans[i]; 
            subset.push_back(a);
            ans.push_back(subset);
        }
        
        nums.push_back(a); 
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        subs(nums,ans);
        return ans;
    }
};