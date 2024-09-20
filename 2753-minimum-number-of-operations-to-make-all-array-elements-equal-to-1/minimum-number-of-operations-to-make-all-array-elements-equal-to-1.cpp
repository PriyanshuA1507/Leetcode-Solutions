class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOps = n; 
        if (count(nums.begin(), nums.end(), 1) > 0) {
         return (n-count(nums.begin(), nums.end(), 1));
        }

        for (int i = 0; i < n; ++i) {
            int gcd_result = nums[i];
            for (int j = i + 1; j < n; ++j) {
                gcd_result = __gcd(gcd_result, nums[j]);
            
                if (gcd_result == 1) {
                    minOps = min(minOps, j - i);  
                    break;
                }
            }
        }
        
        if (minOps == n) {
            return -1;
        }
        return minOps + (n - 1);
    }
};
