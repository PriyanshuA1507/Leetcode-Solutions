class Solution {
public:
    long long minimumSteps(string s) {
        int totalzero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                totalzero++;
            }
        }
        int tempzero=0;
        long long ans=0;
        for(int i=0;i<s.size();i++){
              if(s[i]=='0'){
                  tempzero++;
              }
                if(s[i]=='1'){
               ans+= totalzero-tempzero;
                }
            }
        return ans;
    }
};