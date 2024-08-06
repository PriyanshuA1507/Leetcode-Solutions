class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freqMap;

        
        for (char c : word) {
            freqMap[c]++;
        }

        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

     
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        unordered_map<char, int> m;
        int uniqueChars = 0;

        for (int i = 0; i < freqVec.size(); i++) {
            if (uniqueChars < 8) {
                m[freqVec[i].first] = 1;
            } else if (uniqueChars < 16) {
                m[freqVec[i].first] = 2;
            } else if (uniqueChars < 24) {
                m[freqVec[i].first] = 3;
            } else if (uniqueChars < 26) {
                m[freqVec[i].first] = 4;
            }
            uniqueChars++;
        }
        int ans = 0;
        for (char c : word) {
            ans += m[c];
        }

        return ans;
    }
};