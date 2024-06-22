class Solution {
    bool check(vector<int> &a, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < a.size(); i++) {
            m[a[i]]++;
        }
        for (int i = 0; i < a.size(); i++) {
            if (m[a[i]] > 0 && a[i] % 2 != 0) {
                ans++;
                m[a[i]] = 0;
            }
        }
        return ans >= k;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int count = 0;
        int oddCount = 0;
        unordered_map<int, int> prefixCount;

        prefixCount[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                oddCount++;
            }

            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                count += prefixCount[oddCount - k];
            }

            prefixCount[oddCount]++;
        }

        return count;
    }
};