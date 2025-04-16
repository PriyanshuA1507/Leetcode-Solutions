class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans2;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];

                if (sum == 0) {
                    ans2.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if (sum > 0) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }

        for (const auto& triplet : ans2) {
            ans.push_back(triplet);
        }

        return ans;
    }
};