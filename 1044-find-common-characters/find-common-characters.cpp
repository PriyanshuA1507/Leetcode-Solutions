class Solution {
public:
    vector<string> commonChars(vector<string>& words) { 
        vector<int> minFreq(26, INT_MAX);
        vector<int> firstWordFreq(26, 0);
        for (char c : words[0]) {
            firstWordFreq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            minFreq[i] = firstWordFreq[i];
        }

        for (int i = 1; i < words.size(); i++) {
            vector<int> charCount(26, 0);
            for (char c : words[i]) {
                charCount[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                minFreq[j] = min(minFreq[j], charCount[j]);
            }
        }
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (minFreq[i]-- > 0) {
                result.push_back(string(1, i + 'a'));
            }
        }
        
        return result;
    }
};
