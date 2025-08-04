class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int start = j + 1;
                int end = n - 1;

                while(start < end) {
                    long long a = 1LL * nums[i] + nums[j] + nums[start] + nums[end];

                    if(a == target) {
                        ans.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    } else if(a > target) {
                        end--;
                    } else {
                        start++;
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
