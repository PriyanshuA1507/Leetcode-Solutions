#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;  // Handle edge case of empty ratings

        vector<int> ra(n, 1);  // Start with 1 candy for each child

        // Left to right pass
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                ra[i] = ra[i - 1] + 1;
            }
        }

        // Right to left pass
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                ra[i] = max(ra[i], ra[i + 1] + 1);
            }
        }

        // Calculate the total number of candies
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += ra[i];
        }

        return ans;
    }
};
