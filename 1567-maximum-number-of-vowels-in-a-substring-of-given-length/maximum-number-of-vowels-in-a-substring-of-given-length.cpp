class Solution {
public:
    int maxVowels(string s, int k) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int cv = 0;
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};

        while (end < s.size()) {
            if(v.count(s[end])){
            cv++;
           }
            if (end == start+k-1) {
            
                ans = max(ans, cv);
                if (v.count(s[start])) {
                    cv--;
                }
                start++;
            }
            end++;
        }

        return ans;
    }
};
