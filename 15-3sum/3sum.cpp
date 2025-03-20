class Solution {
public:
 vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
     set<vector<int>> ans2;
    for(int i=0;i<nums.size();i++){
    int start = i + 1;
    int end = nums.size()-1;
    while(start<end){
    if(nums[i]+nums[start]+nums[end]==0){
    ans2.insert({nums[i],nums[start],nums[end]});
        start++;
        end--;
    }
     else if(nums[i]+nums[start]+nums[end]>0){
        end--;
      }
      else {
        start++;
      }
    }
    }
    vector<vector<int>> ans;
    for(auto a:ans2){
            ans.push_back(a);
        }
        return ans;

     }
};