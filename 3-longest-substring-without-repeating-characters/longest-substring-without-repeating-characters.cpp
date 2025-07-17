class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans = 0;
        int start = 0;
        int end = 0;
        while(end<s.size()){
         m[s[end]]++;
         if(m[s[end]]<=1){
        ans = max(ans, end-start+1);
         }
         if(m[s[end]]>1){
         while(m[s[end]]>1){
         m[s[start]]--;
         if(m[s[start]]==0){
          m.erase(s[start]);
         }
         start++;
         }
         ans = max(ans, end-start+1);
         }
         end++;
        }
        return ans;
    }
};