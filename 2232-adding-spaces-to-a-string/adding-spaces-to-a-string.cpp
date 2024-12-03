class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
     string ans = "";
     unordered_map<int,int>m;
     for(int i:spaces){
        m[i]++;
     }
     for(int i=0;i<s.size();i++){
      if(m[i]!=0){
        ans.push_back(' ');
      }
       ans.push_back(s[i]);
     } 
     return ans;
    }
};