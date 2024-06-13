class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        unordered_map<string,int> m;
        string prefix = "";
        for (char c : s) {
            prefix += c;
            m[prefix]++;
        }
        for(int i=0;i<words.size();i++){
            if(m[words[i]]>0){
                ans++;
            }
        }
        return ans;
    }
};