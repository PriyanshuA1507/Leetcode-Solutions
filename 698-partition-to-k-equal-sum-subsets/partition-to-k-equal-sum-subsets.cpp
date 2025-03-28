class Solution {
public:
    bool solve(int index, vector<int>& nums, int target, int k, int ss, vector<bool>& visited) {
        if (k == 0) {
            return true;
        }
        if (ss == target) {
            return solve(0, nums, target, k - 1, 0, visited);
        }
        for (int j = index; j < nums.size(); j++) {
            if (visited[j] || ss + nums[j] > target) {
                continue;
            }
            visited[j] = true;
            if (solve(j + 1, nums, target, k, ss + nums[j], visited)) {
                return true;
            }
            visited[j] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }
        if (totalsum % k != 0) {
            return false;
        }
        int target = totalsum / k;
        vector<bool> visited(n, false);
        sort(nums.rbegin(), nums.rend());  
        return solve(0, nums, target, k, 0, visited);
    }
};
