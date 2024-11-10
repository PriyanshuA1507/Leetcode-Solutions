class Solution {
public:
    void dfs(unordered_map<int,vector<int>> adj,int node,vector<bool>& visited ){
     visited[node] = true;
     for(auto a: adj[node]){
        if(!visited[a]){
        dfs(adj,a,visited);
        }
     }
    }
    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<g.size();i++){
        for(int j=0;j<g[0].size();j++){
            if(g[i][j]==1 ){
            adj[i].push_back(j);
            adj[j].push_back(i);
            }
        }
        }
        int ans = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
        if(!visited[i]){
        dfs(adj,i,visited);
         ans++;
        }
        }
        return ans;
    }
};