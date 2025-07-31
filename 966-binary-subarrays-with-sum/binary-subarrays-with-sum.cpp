class Solution {
public:
    long long solve(vector<int>& nums, int goal) {
        int start = 0, end = 0;
        long long ans = 0;
        long long sum = 0;

        while (end < nums.size()) {
            sum += nums[end];

            while (sum > goal) {
                sum -= nums[start];
                start++;
            }

            ans += (end - start + 1);
            end++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
           if (goal == 0)
            return solve(nums, 0);
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};
