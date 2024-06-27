#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int solve(vector<int>& nums, int index, int n, vector<int>& memo) {
        if (index >= n - 1) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= nums[index]; ++i) {
            if (index + i < n) {
                int temp = solve(nums, index + i, n, memo);
                if (temp != INT_MAX) {
                    ans = min(ans, 1 + temp);
                }
            }
        }
        return memo[index] = ans;
    }

    int jump(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(nums, 0, n, memo);
    }
};
