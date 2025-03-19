class Solution {
public:
    void dfs( unordered_map<int,vector<int>> adj,int u,vector<bool>& visited){
    if(visited[u]){
        return;
    }
    visited[u] = true;
    for(auto v: adj[u]){
     if(!visited[v]){
     dfs(adj,v,visited);
     }
    }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<bool> visited(n,false);
        int ans = 0;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
         if(a[i][j]==1 && i!=j){
          adj[i].push_back(j);
          adj[j].push_back(i);
         }
        }
        }
        for(int i=0;i<n;i++){
          if(!visited[i]){
            ans++;
            dfs(adj,i,visited);
          }
        }
        return ans;
    }
};