class Solution {
public:
    string minWindow(string s, string t) {
   unordered_map<char, int> m;
        for (char c : t) {
            m[c]++;
        }
        
        int count = m.size(); 
        int start = 0, end = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        
        while (end < s.size()) {
            if (m.find(s[end]) != m.end()) {
                m[s[end]]--;
                if (m[s[end]] == 0) {
                    count--;
                }
            }
            
            while (count == 0) { 
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                
                if (m.find(s[start]) != m.end()) {
                    m[s[start]]++;
                    if (m[s[start]] > 0) {
                        count++;
                    }
                }
                
                start++;
            }
            
            end++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};