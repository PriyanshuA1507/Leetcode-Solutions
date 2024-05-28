class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
     long long ans = 0;
        vector<int> sum;

        for (int i = 0; i < nums.size(); i++) {
            int currentSum = 0;
            for (int j = i; j < nums.size(); j++) {
                currentSum += nums[j];
                sum.push_back(currentSum);
            }
        }

        sort(sum.begin(), sum.end());
        for (int i = left - 1; i < right; i++) {
            ans += sum[i];
        }

       
        return ans % 1000000007;
    }
};