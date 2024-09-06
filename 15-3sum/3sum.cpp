class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     set<vector<int>> ans;
     sort(nums.begin(),nums.end());
    
     for(int i=0;i<nums.size();i++){
     int start = i;
     int start2 = i+1;
     int end = nums.size()-1;
     
     while(start2<end){
        if(nums[start]+nums[start2]+nums[end]==0){
            ans.insert({nums[start],nums[start2],nums[end]});
            start2++;
            end--;
        }
        else if(nums[start]+nums[start2]+nums[end]<0){
            start2++;
        }
        else{
            end--;
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