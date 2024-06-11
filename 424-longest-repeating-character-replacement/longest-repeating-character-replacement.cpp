class Solution {
public:
    int characterReplacement(string s, int k) {
    int start=0;
    int end = 0;
    unordered_map<char,int> m;
    int maxf = 0;
    int ans = INT_MIN;
    while(end<s.size()){
           m[s[end]]++;
            maxf = max(maxf, m[s[end]]);

        
            if (end - start + 1 - maxf > k) {
                m[s[start]]--;
                start++;
            }

          
            ans = max(ans, end - start + 1);
            end++;
    }
    return ans;
    }
};