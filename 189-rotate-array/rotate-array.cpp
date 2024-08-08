class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
        k = k % n;  
        vector<int> a(n);

        for (int i = 0; i < k; i++) {
            a[i] = nums[n - k + i];
        }
        for (int i = k; i < n; i++) {
            a[i] = nums[i - k];
        }
        nums = a;
    }
};