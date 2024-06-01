class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
    if(nums.size()==1){
        return 0;
    }
      sort(nums.begin(),nums.end());
      int maxi = nums[nums.size()-1];
      int mini = nums[0];
      if(maxi-mini>2*k){
        return maxi-mini - 2*k;
      }
      return 0;
        
    }
};