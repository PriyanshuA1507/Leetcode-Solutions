class Solution {
public:
    int longestContinuousSubstring(string s) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int count = 0;
        while (end < s.size()) {
            if (end == 0 || s[end] - s[end - 1] == 1) {
                count++;
                end++;
            } else {
                ans = max(count, ans);
                count = 1;  
                end++;
            }
        }
        ans = max(count, ans);  
        return ans;
    }
};
