class Solution {
public:
    int maxVowels(string s, int k) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int currentVowels = 0;
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};

        while (end < s.size()) {

            if (v.count(s[end])) {
                currentVowels++;
            }
            if (end - start + 1 == k) {
            
                ans = max(ans, currentVowels);
                if (v.count(s[start])) {
                    currentVowels--;
                }
                start++;
            }

            end++;
        }

        return ans;
    }
};
