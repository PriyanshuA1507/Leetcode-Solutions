class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> ps(n, 0); 
        ps[0] = nums[0];

    
        for (int i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            int left = i > 0 ? nums[i] * i - ps[i - 1] : 0;
            int right = (ps[n - 1] - ps[i]) - nums[i] * (n - i - 1);
            ans[i] = left + right;
        }

        return ans;
    }
};
