class Solution {
public:
   void solve(int open,int close,vector<string>& ans,string a){
   if(open==0 && close==0){
    ans.push_back(a);
    return;
   }
 if(open>0){
solve(open-1,close,ans,a+"(");
 }
 if(close>open){
solve(open,close-1,ans,a+")");
 }
 }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string a = "";
        solve(n,n,ans,a);
        return ans;
    }
};