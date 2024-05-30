class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
    for(int i=s.size()-1;i>=0;i--){
        if(m[s[i]]<=0){
            m[s[i]]=i;
        }
    }
       vector<int> ans;
       for(int i=0;i<s.size();){
        int start = i;
        int end = m[s[i]];
        for(int j = start+1;j<=end;j++){
            if(m[s[j]]>end){
                end = m[s[j]];
            }
        }
        ans. push_back(end - start +1);
        i = end+1;
       } 
       return ans;
    }
};