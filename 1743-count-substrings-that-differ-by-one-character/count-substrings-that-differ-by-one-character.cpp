class Solution {
public:
 int solve(int i,int j,bool diff,string s,string t){
    if(i==s.size()|| j==t.size()){
        return 0;
    }
    if(diff){
      if(s[i]!=t[j]){
        return 0;
      } 
      return 1 + solve(i+1,j+1,diff,s,t);
    }
    if(s[i]!=t[j]){
        return 1 + solve(i+1,j+1,true,s,t);
    }
    return solve(i+1,j+1,diff,s,t);
 }
    int countSubstrings(string s, string t) {
        int ans =0;
     for(int i=0;i<s.size();i++){
    for(int j=0;j<t.size();j++){
       ans +=solve(i,j,false,s,t);
    }
     }
     return ans;   
    }
};