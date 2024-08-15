class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int o = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                o++;
            }
            else if(s[i]==')'){
                o--;
            }
            maxi = max(o,maxi);
        }
        return maxi;
    }
};
