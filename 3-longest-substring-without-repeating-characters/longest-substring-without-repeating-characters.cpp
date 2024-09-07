class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        unordered_map<char,int> m;
        int ans = INT_MIN;
        int i = 0 , j =0;
        while(j<s.size()){
            m[s[j]]++;
            if(m[s[j]]>1){
             while(m[s[j]]!=1){
              m[s[i]]--;
              if(m[s[i]]==0){
                m.erase(s[i]); 
               }
              i++;
             }
            }
         ans = max(ans,j-i+1);
         j++;
        }
        return ans;
    }
};