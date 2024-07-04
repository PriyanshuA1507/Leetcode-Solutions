class Solution {
public:
    int percentageLetter(string s, char l) {
        unordered_map<int,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        double ans = ((m[l]*100)/s.size());
        return ans;
    }
};