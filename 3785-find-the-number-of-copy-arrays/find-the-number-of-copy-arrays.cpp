#include <vector>
using namespace std;

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int left = bounds[0][0];
        int right = bounds[0][1];

        for (int i = 1; i < bounds.size(); i++) {
            int diff = original[i] - original[i - 1];

            left = max(left + diff, bounds[i][0]);
            right = min(right + diff, bounds[i][1]);

            if (left > right) return 0; 
        }

        return max(0, right - left + 1);
    }
};
