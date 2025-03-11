class Solution {
public:
    int numberOfSubstrings(string s) {
        int start = 0;
        int end =0;
        int ans = 0;
        unordered_map<char,int> m;
        while(end<s.size()){
            m[s[end]]++;
          while(m['a']>0 && m['b']>0 && m['c']>0){
          ans+=(s.size()-end);
          if((start>=0 && start<s.size()) || m[s[start]]=='a' || m[s[start]]=='b' || m[s[start]]=='c'){
           m[s[start]]--;
           if(m[s[start]]==0){
            m.erase(s[start]);
           }
          }
          start++;
          }
          end++;
        }
        return ans;
    }
};