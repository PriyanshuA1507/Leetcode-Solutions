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
        int ans = 0;

        for(int it : a) {
            // Check if 'it - 1' is not in the set, which means 'it' could be the start of a new sequence
            if(a.find(it - 1) == a.end()) {
                int currentNum = it;
                int currentStreak = 1;

                // Continue the sequence
                while(a.find(currentNum + 1) != a.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                ans = std::max(ans, currentStreak);
            }
        }

        return ans;
    }
};