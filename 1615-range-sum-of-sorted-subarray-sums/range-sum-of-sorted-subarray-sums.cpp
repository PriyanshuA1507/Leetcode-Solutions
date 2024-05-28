class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
     long long ans = 0;
        vector<int> sum;

        // Generate all subarray sums
        for (int i = 0; i < nums.size(); i++) {
            int currentSum = 0;
            for (int j = i; j < nums.size(); j++) {
                currentSum += nums[j];
                sum.push_back(currentSum);
            }
        }

        // Sort all subarray sums
        sort(sum.begin(), sum.end());

        // Calculate the sum from the 'left' to 'right' range
        for (int i = left - 1; i < right; i++) {
            ans += sum[i];
        }

        // Since the problem might require the result modulo 10^9 + 7
        return ans % 1000000007;
    }
};