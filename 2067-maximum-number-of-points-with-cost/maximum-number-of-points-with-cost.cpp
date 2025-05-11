#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> prev(points[0].begin(), points[0].end()); // first row

        for (int i = 1; i < n; ++i) {
            vector<long long> left(m), right(m), curr(m);

            // Left to right
            left[0] = prev[0];
            for (int j = 1; j < m; ++j) {
                left[j] = max(left[j - 1] - 1, prev[j]);
            }

            // Right to left
            right[m - 1] = prev[m - 1];
            for (int j = m - 2; j >= 0; --j) {
                right[j] = max(right[j + 1] - 1, prev[j]);
            }

            // Current row's dp
            for (int j = 0; j < m; ++j) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};
