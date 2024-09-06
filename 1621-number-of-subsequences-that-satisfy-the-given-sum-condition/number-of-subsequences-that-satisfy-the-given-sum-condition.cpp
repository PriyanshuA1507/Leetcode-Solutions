class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7; // To prevent overflow, take result modulo 1e9 + 7
        int start = 0;
        int end = nums.size() - 1;
        int ans = 0;
        
        // Precompute powers of 2 up to nums.size()
        vector<int> pow2(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        
        // Two-pointer approach
        while (start <= end) {
            if (nums[start] + nums[end] <= target) {
                ans = (ans + pow2[end - start]) % mod;
                start++;
            } else {
                end--;
            }
        }
        
        return ans;
    }
};
