class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int ans = 0, count = 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
                ans = max(ans, count);
            } else {
                count = 0;
            }
        }
        return ans;
    }
};