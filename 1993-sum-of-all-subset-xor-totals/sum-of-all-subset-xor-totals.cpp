class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
         int xorSum = 0;
        for (int num : nums) {
            xorSum |= num; 
        }
        return xorSum * (1 << (nums.size() - 1));
    }
};