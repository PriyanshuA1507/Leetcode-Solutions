class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> delta;
        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            delta[start]++;
            delta[end + 1]--;
        }

        int coveredDays = 0;
        int currentActive = 0;
        int lastDay = 0;

        for (auto it = delta.begin(); it != delta.end(); ++it) {
            if (currentActive > 0) {
                coveredDays += it->first - lastDay;
            }
            currentActive += it->second;
            lastDay = it->first;
        }

        return days - coveredDays;
    }
};