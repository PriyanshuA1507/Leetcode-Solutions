class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        
       
        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0] - 1;  
            int v = relations[i][1] - 1;  
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> min_time(n, 0);  
        
      
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                min_time[i] = time[i];  
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                min_time[neighbor] = max(min_time[neighbor], min_time[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }

            ans = max(ans, min_time[node]);  
        }

        return ans;
    }
};
