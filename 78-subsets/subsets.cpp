class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsetCount = (1 << n);  
        vector<vector<int>> ans;

        for (int num = 0; num < subsetCount; num++) {
            vector<int> a;
            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {  
                    a.push_back(nums[i]);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};