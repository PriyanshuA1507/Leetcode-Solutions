class Solution {
public:
    string findValidPair(string s) {
        string ans="";
        unordered_map<int,int>m;
          for(int i=0;i<s.size();i++){
            m[s[i]]++;
          }
        for(int i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1] && s[i]-'0'==m[s[i]] && s[i+1]-'0'==m[s[i+1]]){
            ans.push_back(s[i]);
            ans.push_back(s[i+1]);
            return ans;
        }
        }
        return ans;
    }
};