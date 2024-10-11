class Solution {
public:
     void dfs(unordered_map<int,vector<int>> adj,vector<bool>& vis,int u){
        vis[u]=true;
        for(auto a:adj[u]){
         if(!vis[a]){
            dfs(adj,vis,a);
         }
        }
     }
    int findCircleNum(vector<vector<int>>& m) {
        int a = m.size();
        int b = m[0].size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
          if(m[i][j]==1 && i!=j){
            adj[i].push_back(j);
         }
            }
        }
        vector<bool> vis(a,0);
        int ans=0;
        for(int i=0;i<a;i++){
        if(!vis[i]){
        ans++;
        dfs(adj,vis,i);
        }
        }
        return ans;
    }
};