class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> ans;
     sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size();i++){
      for(int j=i+1;j<nums.size();j++){
        int start3 = j+1;
        int end = nums.size()-1;
        while(start3<end){
        long long a = (long long)nums[i] + (long long)nums[j] + (long long)nums[start3] + (long long)nums[end];
        if(a==target){
            ans.insert({nums[i],nums[j],nums[start3],nums[end]});
            start3++;
            end--;
        }
        else if(a<target){
            start3++;
        }
        else{
            end--;
        }
        }
      }
     }
     vector<vector<int>> ans1;   
     for(auto a:ans){
        ans1.push_back(a);
     }
     return ans1;
    }
};