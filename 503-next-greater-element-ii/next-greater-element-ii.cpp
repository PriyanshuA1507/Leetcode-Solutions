class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      vector<int> ans;
      vector<int> a = nums;
      for(int i =0;i<nums.size();i++){
        a.push_back(nums[i]);
      }
      for(int i=0;i<a.size()/2;i++){
        int b = -1;
       for(int j=i+1;j<a.size();j++){
        if(a[i]<a[j]){
            b = a[j];
           break;
        }
       }
       ans.push_back(b);
      }
      return ans;
    }
};