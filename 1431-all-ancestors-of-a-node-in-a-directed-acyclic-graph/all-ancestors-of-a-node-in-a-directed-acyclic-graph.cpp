class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
     vector<vector<int>> ans(n);
        vector<set<int>> ancestors(n);
        vector<int> adj[n];
        vector<int> indegree(n, 0);
      
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor : adj[current]) {

                ancestors[neighbor].insert(current);
                ancestors[neighbor].insert(ancestors[current].begin(), ancestors[current].end());
              
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        
        return ans;
    }
};