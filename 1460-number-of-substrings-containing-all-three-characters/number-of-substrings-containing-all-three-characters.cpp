class Solution {
public:
    int numberOfSubstrings(string s) {
        int start = 0;
        int end = 0;
        int ans =0;
        unordered_map<char,int>m;
        while(end<s.size()){
        m[s[end]]++;
        if(m['a']>0 && m['b']>0 && m['c']>0){
        ans+=(s.size()-end);
        }
        while(m['a']>0 && m['b']>0 && m['c']>0){
        m[s[start]]--;
        if(m[s[start]]==0){
         m.erase(m[s[start]]);
        }
        if(m['a']>0 && m['b']>0 && m['c']>0){
        ans+=(s.size()-end);
        }
        start++;
        }
        end++;
        }
        return ans;
    }
};