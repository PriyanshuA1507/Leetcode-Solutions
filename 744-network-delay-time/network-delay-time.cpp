class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        // Building the adjacency list for the directed graph
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        // Min-heap to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Initializing result vector with size n+1 to accommodate nodes from 1 to n
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;  // Start from node k
        pq.push({0, k});

        // Dijkstra's algorithm
        while (!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            int dist1 = a.first;
            int node = a.second;

            for (auto& b : adj[node]) {
                int nnode = b.first;
                int dist2 = b.second;
                if (dist1 + dist2 < result[nnode]) {
                    result[nnode] = dist1 + dist2;
                    pq.push({result[nnode], nnode});
                }
            }
        }
         int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (result[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, result[i]);
        }
        return ans;
    }
};