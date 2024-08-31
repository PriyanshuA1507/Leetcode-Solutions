class Solution {
public:
  int result = -1;
    void dfs(int u,vector<int>& edges,vector<bool> &vis, vector<int>& dist, vector<bool>& inr){
    if(u!=-1){
    vis[u]= true;
    inr[u] = true;
    int v = edges[u];
    if(v!=-1 && !vis[v]){
        dist[v] = dist[u]+1;
     dfs(v,edges,vis,dist,inr);
    }
    else if(v!=-1 && inr[v]){
    result = max(result,dist[u]-dist[v]+1);
    }
    inr[u] = false;
    }
    }
    int longestCycle(vector<int>& edges) {
      int n =edges.size();
      vector<bool> vis(n,false);
      vector<int> dist(n,1);
      vector<bool> inr(n,false);
      for(int i=0;i<n;i++){
       if(!vis[i]){
        dfs(i, edges,vis,dist,inr);
       }
      }
      return result;
    }
};