class Solution {
public:
    int solve(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        return solve(nums, target, index + 1, sum - nums[index]) + 
               solve(nums, target, index + 1, sum + nums[index]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};
