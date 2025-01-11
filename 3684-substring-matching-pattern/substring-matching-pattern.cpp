class Solution {
public:
    bool hasMatch(string s, string p) {
    int i = p.find('*');
    string pre = p.substr(0,i);
    string suf = p.substr(i+1);

    int pi = s.find(pre);
    if(pi==string::npos) return false;
     
    int si = s.find(suf,pi+pre.size());
    if(si==string::npos) return false;
        
      return true;  
    }
};