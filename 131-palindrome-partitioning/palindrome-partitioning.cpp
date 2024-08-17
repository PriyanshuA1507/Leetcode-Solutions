class Solution {
public:
   bool isp(string s){
    int si = 0;
    int ei = s.size()-1;
    while(si<ei){
        if(s[si]!=s[ei]){
            return false;
        }
        si++;
        ei--;
    }
    return true;
   }
   void solve(string s,int index,vector<string>& curr,vector<vector<string>>& ans){
    if(index==s.size()){
        ans.push_back(curr);
        return;
    }
  
    
    for(int i= index;i<s.size();i++){
       string a = s.substr(index, i-index+1);
       if(isp(a)){
        curr.push_back(a);
        solve(s,i+1,curr,ans);
        curr.pop_back();
       }
    }
   }
    vector<vector<string>> partition(string s) {
      vector<string> curr;
      vector<vector<string>> ans;
      solve(s,0,curr,ans); 
      return ans; 
    }
};