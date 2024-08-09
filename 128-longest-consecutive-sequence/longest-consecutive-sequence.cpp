class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        if(nums.size() == 1) {
            return 1;
        }

        set<int> a(nums.begin(), nums.end());
        int length = 0;
        int start = *a.begin();  
        int ans = 1;  

        for(int it : a) {
            if(it == start) {
                length = 1;
            } else if(it == start + 1) {
                length++;
            } else {
                length = 1;
            }
            start = it;
            ans =max(ans, length);
        }

        return ans;
    }
};