class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        
        unordered_map<int, int> m;
        m[0] = -1; 
        int cs = 0; // cumulative sum
        
        for (int i = 0; i < nums.size(); i++) {
            cs += nums[i];
            int rem = cs % k;
            if (rem < 0) rem += k; // to handle negative remainders
            if (m.find(rem) != m.end()) {
                if (i - m[rem] > 1) {
                    return true;
                }
            } else {
                m[rem] = i;
            }
        }
        
        return false;
    }
};
