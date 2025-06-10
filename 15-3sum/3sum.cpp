class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
       vector<vector<int>>  ans;
        sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size();i++){
      int start = i+1;
      int end = nums.size()-1;
      while(start<end){
      if(nums[i]+nums[start]+nums[end]==0){
      s.insert({nums[i],nums[start],nums[end]});
      start++;
      end--;
      }
      else if(nums[i]+nums[start]+nums[end]>0){
    end--;
      }
      else if(nums[i]+nums[start]+nums[end]<0){
    start++;
      }
      }
      }
     
      for(auto a:s){
        ans.push_back(a);
      }
      return ans;
    }
};