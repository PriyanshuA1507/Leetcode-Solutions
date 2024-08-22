class Solution {
public:
    bool canwe(vector<int>& nums, int k, int mid) {
        int n = nums.size();
        int ds = 1;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] > mid) {
                ds++;
                sum = nums[i];
                if (ds > k) {
                    return false;
                }
            } else {
                sum += nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            sum += nums[i];
        }

        int low = maxi;
        int high = sum;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canwe(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
