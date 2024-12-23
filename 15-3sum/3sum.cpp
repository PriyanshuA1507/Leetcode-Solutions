class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> ans2;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int start2 = i+1;
            int end = nums.size()-1;
            while(start2<end){
             if(nums[i]+nums[start2]+nums[end]==0){
             ans.insert({nums[i],nums[start2],nums[end]});
             start2++;
             end--;
             }
             else if(nums[i]+nums[start2]+nums[end]>0){
                end--;
             }
             else{
                start2++;
             }
            }
        }
        for(auto a:ans){
            ans2.push_back(a);
        }
        return ans2;
    }
};