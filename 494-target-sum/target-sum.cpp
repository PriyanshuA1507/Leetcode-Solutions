class Solution {
public:
   int solve(vector<int>& nums, int target,int index){
    if(index>=nums.size()){
        if(target==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int o1 = solve(nums,target+nums[index],index+1);
     int o2 = solve(nums,target-nums[index],index+1);

     return o1+o2;
       }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0);
    }
};