class Solution {
public:
  vector<int> par;
   int findpar(int n){
    if(par[n]==n)
    return n;
    return par[n] =findpar(par[n]);
   }
   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1);
    for(int i=0;i<=n;i++)
     par[i] = i;
     for(vector<int>& e : edges){
        int u = e[0], v = e[1];
        int p1 = findpar(u), p2 = findpar(v);
        if(p1!=p2){
            par[p1] = p2;
        }
        else{
            return e;
        }
     }
     return {};
    }
};