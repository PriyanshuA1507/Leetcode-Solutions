class Solution {
public:
    bool ispa(string& s,int i, int j){
     if(i>=j){
        return true;
     }
     if(s[i] != s[j]){
        return false;
     }
     return ispa(s,i+1,j-1);
    }
    string longestPalindrome(string s) {
      int n = s.length();
      if(n == 0) return "";

      string ans = "";
      int ml = 0;
      for(int i=0;i<n;++i){
     for(int j=i;j<n;++j){
        if(ispa(s,i,j)){
        int cl = j- i + 1;
        if(cl> ml){
         ml = cl;
         ans = s.substr(i,cl);
        }
        }
     }
      }  
      return ans;
    }
};