class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
      unordered_map<int,int>m;
    for(int i=0;i<s.size();i++){
        if(m[s[i]]>0){
        m.clear();
        ans++;
        i--;
        }
        else{
            m[s[i]]++;
        }
    }
    return ans+1;
    }
};