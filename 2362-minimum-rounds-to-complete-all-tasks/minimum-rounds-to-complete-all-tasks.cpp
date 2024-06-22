class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        int ans = 0;

        for (int task : tasks) {
            m[task]++;
        }

        for (auto& entry : m) {
            int count = entry.second;
        
            if (count == 1) {
                return -1;
            }
            if (count % 3 == 0) {
                ans += count / 3;
            } else {
                ans += count / 3 + 1;
            }
        }

        return ans;
    }
};
