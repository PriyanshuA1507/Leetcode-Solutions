#include <vector>
#include <numeric>  // For std::gcd
#include <algorithm>  // For std::sort
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOps = n;  // Initialize with maximum possible operations
        if (count(nums.begin(), nums.end(), 1) > 0) {
         return (n-count(nums.begin(), nums.end(), 1));
        }
        // Try to find the minimum subarray with GCD 1
        for (int i = 0; i < n; ++i) {
            int gcd_result = nums[i];
            for (int j = i + 1; j < n; ++j) {
                gcd_result = __gcd(gcd_result, nums[j]);
                
                // If we found a subarray with GCD 1, calculate operations
                if (gcd_result == 1) {
                    minOps = min(minOps, j - i);  // Calculate minimal operations for this subarray
                    break;
                }
            }
        }
        
        // If no subarray with GCD 1 is found, return -1
        if (minOps == n) {
            return -1;
        }

        // Total operations: operations to turn the subarray into 1, and the rest of the array
        return minOps + (n - 1);
    }
};
