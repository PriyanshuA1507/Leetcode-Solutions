class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        unordered_map<char,int> m1,m2;
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
           m2[s[i]]++;
           m1[s[i]]--;
           if(m1[s[i]]==0){
            m1.erase(s[i]);
           }
           if(m1.size()==m2.size()){
            ans++;
           }
        }
        return ans;
    }
};