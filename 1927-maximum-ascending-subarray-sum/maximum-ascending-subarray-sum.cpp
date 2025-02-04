class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum = 0, sum = nums[0]; // Start with first element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { // Ascending condition
                sum += nums[i];
            } else {
                maxsum = max(maxsum, sum); // Update maxsum
                sum = nums[i]; // Reset sum for new subarray
            }
        }
        return max(maxsum, sum); // Final check
    }
};