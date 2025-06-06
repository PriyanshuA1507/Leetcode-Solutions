class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> m;
        long long count = 0, ans = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            count += m[nums[end]];  
            m[nums[end]]++;

            while (count >= k) {
                ans += (nums.size() - end);  
                m[nums[start]]--;
                count -= m[nums[start]];  
                start++;
            }
        }

        return ans;
    }
};
