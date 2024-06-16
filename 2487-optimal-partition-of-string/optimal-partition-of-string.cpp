class Solution {
public:
    int partitionString(string s) {
        int ans =1;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]>0){
                ans++;
                m.clear();
            }
         m[s[i]]=1;

        }
        return ans;
    }
};