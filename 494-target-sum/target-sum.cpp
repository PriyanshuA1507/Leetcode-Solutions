class Solution {
public:
   int solve(vector<int>& nums, int target,int index){
    if(index>=nums.size()){
        return target==0;
    }
    int add = solve(nums, target - nums[index], index + 1);
       int sub = solve(nums, target + nums[index], index + 1);

    return add+sub;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0);
    }
};