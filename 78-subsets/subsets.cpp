class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> ans;
      int subsetcount = (1<<n);
      for(int i=0;i<subsetcount;i++){
      vector<int> a;
      for(int j=0;j<n;j++){
        if(i &(1<<j)){
        a.push_back(nums[j]);
        }
      }
      ans.push_back(a);
      }
      return ans;  
    }
};