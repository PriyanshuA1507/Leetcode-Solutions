class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> a;
        for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            a.push(i);
        }
        else if(s[i]==')'){
         int c = a.top();
         a.pop();
         reverse(s.begin()+c+1,s.begin()+i);
        }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')'){
            ans.push_back(s[i]);}
        }
        return ans;
    }
};