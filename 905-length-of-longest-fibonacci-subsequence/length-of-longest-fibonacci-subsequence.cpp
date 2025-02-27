#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int index1, int index2, vector<vector<int>>& dp, unordered_map<int, int>& indexMap) {
        if (indexMap.find(arr[index1] + arr[index2]) == indexMap.end()) {
            return 0;
        }

        int index3 = indexMap[arr[index1] + arr[index2]];
        if (dp[index2][index3] != -1) {
            return dp[index2][index3];
        }

        return dp[index2][index3] = 1 + solve(arr, index2, index3, dp, indexMap);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> indexMap;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            indexMap[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int length = 2 + solve(arr, i, j, dp, indexMap);
                ans = max(ans, length);
            }
        }

        return ans > 2 ? ans : 0;
    }
};
