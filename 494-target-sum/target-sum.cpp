class Solution {
public:
  int solve(vector<int>& nums, int target,int index){
    int n = nums.size();
    if(index==n){
       if(target==0){
        return 1;
       }
       return 0;
    }
    int add = solve(nums,target+nums[index],index+1);
    int s = solve(nums,target - nums[index],index+1);
     return add+s;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0);
    }
};