class Solution {
public:
    using p = pair<long long, int>;  // Use long long for the distance to prevent overflow

    int countPaths(int n, vector<vector<int>>& roads) {
        // Adjacency list where each node has a vector of pairs (neighbor, weight)
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // Vector to store the minimum distance to each node
        vector<long long> result(n, LLONG_MAX);  // Use long long for distance
        result[0] = 0;

        // Vector to store the number of ways to reach each node with the shortest path
        vector<int> ways(n, 0);
        ways[0] = 1;

        // Priority queue to store (distance, node), using greater<long long> to create a min-heap
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});

        // Modulo constant to avoid overflow
        const int MOD = 1e9 + 7;

        while(!pq.empty()) {
            long long d = pq.top().first;  // Use long long for the current distance
            int node = pq.top().second;
            pq.pop();

            // Process each neighbor of the current node
            for(auto& v : adj[node]) {
                int neighbor = v.first;
                int d2 = v.second;

                if(d + d2 < result[neighbor]) {
                    result[neighbor] = d + d2;
                    ways[neighbor] = ways[node];  // Update the number of ways to reach the neighbor
                    pq.push({result[neighbor], neighbor});
                } else if(d + d2 == result[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;  // Add up the ways
                }
            }
        }

        return ways[n-1];  // Return the number of ways to reach the last node
    }
};