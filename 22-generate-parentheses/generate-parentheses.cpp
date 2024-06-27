class Solution {
public:
    void solve(int o,int c, string a,vector<string>& p){
     if(o==0 && c==0){
        p.push_back(a);
        return;
     }
     if(o>0) solve(o-1,c,a+"(",p);
     if(c>o) solve(o,c-1,a+")",p);
    }
    vector<string> generateParenthesis(int n) {
       vector<string> p;
       solve(n,n,"",p);
       return p; 
    }
};