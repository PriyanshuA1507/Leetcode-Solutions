class Solution {
public:
    string getEncryptedString(string s, int k) {
     string a;
     for(int i=0;i<s.size();i++){
        a.push_back(s[(i+k)%s.size()]);
     }
     return a;   
    }
};