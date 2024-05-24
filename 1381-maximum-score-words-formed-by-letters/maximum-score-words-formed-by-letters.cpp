class Solution {
public:
    int wordScore(string& s, unordered_map<char, int>& m, vector<int>& score) {
        int s1 = 0;
        unordered_map<char, int> tempMap = m;
        
        for (char ch : s) {
            if (tempMap[ch] > 0) {
                s1 += score[ch - 'a'];
                tempMap[ch]--;
            } else {
                return 0; 
            }
        }
        
       
        m = tempMap;
        return s1;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> m1;
        for (char ch : letters) {
            m1[ch]++;
        }
        
        int ms = 0;
        
        int n = words.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            unordered_map<char, int> tempMap = m1;
            int sc = 0;
            
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) { 
                    int wordSc = wordScore(words[i], tempMap, score);
                    if (wordSc == 0) { 
                        sc = 0;
                        break;
                    }
                    sc += wordSc;
                }
            }
            
            ms = max(ms, sc);
        }
        
        return ms;
    }
};
