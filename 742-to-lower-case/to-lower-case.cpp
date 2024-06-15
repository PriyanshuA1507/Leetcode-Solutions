class Solution {
public:
    string toLowerCase(string s) {
       string a="";
       for(int i=0;i<s.size();i++){
        a.push_back(tolower(s[i]));
       } 
       return a;
    }
};