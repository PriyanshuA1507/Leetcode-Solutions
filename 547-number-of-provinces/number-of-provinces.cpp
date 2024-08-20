class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        if (visited[u]) {
            return;
        }
        visited[u] = true;
        for (int &v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) { 
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited);
                result++; 
            }
        }
        
        return result;
    }
};
