class Solution {
public:
    string removeOuterParentheses(string s) {
         int o=0;
        int si= -1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(si==-1){
                    si = i;
                }
                o++;
            }
            if(s[i]==')' ){
                o--;
                if(o==0){
                 s[si]='0';
                 s[i]='0';
                 si = -1;
                }
            }
        }
        string ans = "";
        for(auto a:s){
            if(a!='0'){
                ans.push_back(a);
            }
        }
        return ans;
    }
};