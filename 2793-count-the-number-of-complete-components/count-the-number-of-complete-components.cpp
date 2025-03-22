class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int s, int& nc, int& ec) {
        vis[s] = true;
        nc+=1;
        ec+=adj[s].size();  
        for(auto i : adj[s]) {  
            if(!vis[i]) {
                dfs(adj, vis, i, nc, ec);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);  
        vector<bool> vis(n, false);
        

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nc = 0, ec = 0;
                dfs(adj, vis, i, nc, ec);
                if (ec == nc * (nc - 1)) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};