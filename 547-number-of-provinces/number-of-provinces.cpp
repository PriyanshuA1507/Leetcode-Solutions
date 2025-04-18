class Solution {
public:
    void dfs(int i, unordered_map<int,vector<int>> adj,vector<bool>& visited){
    visited[i] = true;
    for(auto a:adj[i]){
    if(!visited[a]){
     dfs(a,adj,visited);
    }
    }
    }
    int findCircleNum(vector<vector<int>>& ic) {
    int ans =0 ;
    int n = ic.size();
    int m = ic[0].size();
     unordered_map<int,vector<int>> adj;
     for(int i=0;i<ic.size();i++){
      for(int j=0;j<m;j++){
      if(ic[i][j]==1){
      adj[i].push_back(j);
      adj[j].push_back(i);
      }
      }
     }
      vector<bool> visited(n,false);
      for(int i=0;i<n;i++){
      if(!visited[i]){
        ans++;
        dfs(i,adj,visited);
      }
      }
      return ans;  
    }
};