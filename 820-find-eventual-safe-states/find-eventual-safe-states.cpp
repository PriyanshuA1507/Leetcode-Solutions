class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> graph1(n);  // Initialize graph1 with n empty vectors
        vector<int> indegree(n, 0);
        
        // Build the reversed graph and calculate the in-degrees
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                graph1[graph[i][j]].push_back(i);  
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int vtx = q.front();
            q.pop();
            ans.push_back(vtx);
            for (int v : graph1[vtx]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
