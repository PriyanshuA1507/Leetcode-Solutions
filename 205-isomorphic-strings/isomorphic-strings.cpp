class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,char>m1;
        unordered_map<char,int>m2;
        unordered_map<char,int>m3;
        for(int i=0;i<s.size();i++){
            if(m2[s[i]]==0){
            m1[s[i]]= t[i];
            m2[s[i]]++;
            m3[t[i]]++;}
            if(m2[s[i]]>0 && m1[s[i]]!=t[i]){
                return false;
            }
            if(m3[t[i]]>1){
                return false;
            }
        }
        for(int i=0;i<s.size();i++){
            if(m1[s[i]]!=t[i] ){
                return false;
            }
        }
      return true;
    }
};