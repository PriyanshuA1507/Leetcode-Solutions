class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
 set<vector<int>> ans;
     sort(nums.begin() , nums.end());
     for(int i=0;i<nums.size();i++){
     int start = i+1;
     int end = nums.size()-1;
     while(start<end){
      if(nums[i]+ nums[start]+nums[end]==0){
       ans.insert({nums[i],nums[start],nums[end]});
       start++;
       end--;
      }
       else if(nums[i]+ nums[start]+nums[end]>0){
        end--;
      }
       else if(nums[i]+ nums[start]+nums[end]<0){
        start++;
      }
     }
     }
     vector<vector<int>> ans2;
     for(auto a:ans){
     ans2.push_back(a);
     }
     return ans2;   
    }
};