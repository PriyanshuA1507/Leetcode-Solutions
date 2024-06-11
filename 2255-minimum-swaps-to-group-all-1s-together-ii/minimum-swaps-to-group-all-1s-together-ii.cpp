#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    // Function to count the number of zeros in the range [start, end)
    int countZeros(const vector<int>& a, int start, int end) {
        int ans = 0;
        for (int i = start; i < end; i++) {
            if (a[i] == 0) {
                ans++;
            }
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int c = std::count(nums.begin(), nums.end(), 1); // Count the number of ones

        // If there are no ones, no swaps are needed
        if (c == 0) {
            return 0;
        }

        // Double the array to handle the circular nature
        vector<int> a(nums.begin(), nums.end());
        a.insert(a.end(), nums.begin(), nums.end());

        // Initialize the sliding window variables
        int start = 0, end = 0;
        int total = INT_MAX;
        int zerosInWindow = 0;

        // Initialize the window
        for (int i = 0; i < c; i++) {
            if (a[i] == 0) {
                zerosInWindow++;
            }
        }
        total = min(total, zerosInWindow);

        // Slide the window
        for (int i = c; i < a.size(); i++) {
            if (a[i] == 0) {
                zerosInWindow++;
            }
            if (a[start] == 0) {
                zerosInWindow--;
            }
            start++;
            total = min(total, zerosInWindow);
        }

        return total;
    }
};


