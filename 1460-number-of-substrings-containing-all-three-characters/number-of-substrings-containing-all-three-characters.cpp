class Solution {
public:
    int numberOfSubstrings(string s) {
      int start = 0;
      int ans = 0; 
      int end = 0;
      unordered_map<char,int> m;
      while(end < s.size()){
        m[s[end]]++;
        while(m['a']>0 && m['b']>0 && m['c']>0){
            ans += (s.size()-end);
            m[s[start]]--;
            start++;   
        }
        end++;
      }
      return ans;  
    }
};