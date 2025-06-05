class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = -1e8;
        int oc = 0;
        int start = 0;
        int end = 0;
        while(end<s.size()){
         if(s[end]=='a' || s[end]=='e' || s[end]=='i' || s[end]=='o' || s[end]=='u'){
          oc++;
         }
         if(end-start+1==k){
         ans = max(ans,oc);
         }
         if(end-start+1>k){
         while(end-start+1>k){
          if(s[start]=='a' || s[start]=='e' || s[start]=='i' || s[start]=='o' || s[start]=='u'){
            oc--;
          }
          start++;
         }
         }
         ans = max(ans,oc);
         end++;
        }
        return ans;
    }
};