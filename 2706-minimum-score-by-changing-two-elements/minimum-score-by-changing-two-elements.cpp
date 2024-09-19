class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // Case 1: Change the two largest values
        int option1 = nums[n-3] - nums[0];
        
        // Case 2: Change the largest and the smallest value
        int option2 = nums[n-2] - nums[1];
        
        // Case 3: Change the two smallest values
        int option3 = nums[n-1] - nums[2];
        
        // The minimized sum is the minimum of the three options
        return min({option1, option2, option3});
    }
};
