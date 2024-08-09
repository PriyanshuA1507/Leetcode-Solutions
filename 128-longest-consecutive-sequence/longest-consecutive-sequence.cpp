class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        if(nums.size() == 1) {
            return 1;
        }

        std::set<int> a(nums.begin(), nums.end());
        int length = 0;
        int start = *a.begin();  // Initialize start with the first element in the set
        int ans = 1;  // Start with 1 because a single number is a valid sequence

        for(int it : a) {
            if(it == start) {
                // Continue if it's the first element
                length = 1;
            } else if(it == start + 1) {
                // Continue the sequence
                length++;
            } else {
                // Reset the sequence if it breaks
                length = 1;
            }
            start = it;
            ans = std::max(ans, length);
        }

        return ans;
    }
};