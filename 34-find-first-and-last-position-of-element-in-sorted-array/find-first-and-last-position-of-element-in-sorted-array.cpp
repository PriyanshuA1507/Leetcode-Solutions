class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 1 && target == nums[0]) {
            return {0, 0};
        }

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                int left = mid, right = mid;

                // Find the left boundary of the range
                while (left > 0 && nums[left - 1] == target) {
                    left--;
                }

                // Find the right boundary of the range
                while (right < nums.size() - 1 && nums[right + 1] == target) {
                    right++;
                }

                return {left, right};
            }

            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return {-1, -1};
    }
};