class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int start = 0;
     int end = 0;
     int ans = 0;
     unordered_map<char,int> m;
     while(end<s.size()){
      m[s[end]]++;
      if(m[s[end]]==1){
       ans = max(ans, end-start+1);
      }
      else if(m[s[end]]>1){
      while(m[s[end]]>1){
       m[s[start]]--;
       if(m[s[start]]==0){
        m.erase(s[start]);
       }
       start++;
      }
      ans = max(ans,end-start+1);
      }
      end++;
     }
     return ans;
    }
};