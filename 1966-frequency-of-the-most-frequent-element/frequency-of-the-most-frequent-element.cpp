class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<long long> pre(nums.size(), 0);
        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        int maxi = 1;
        for (int i = nums.size() - 1; i >= 1; i--) {
            int l = 0;
            int h = i - 1;
            while (l <= h) {
                int mid = (l + h) / 2;
                long long required = (long long)nums[i] * (i - mid) - (pre[i - 1] - (mid > 0 ? pre[mid - 1] : 0));
                if (required <= k) {
                    maxi = max(maxi, i - mid + 1);
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return maxi;
    }
};