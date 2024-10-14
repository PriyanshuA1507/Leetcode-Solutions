class Solution {
public:
    using p = tuple<int, int, int>;  // (current cost, current node, current stop count)

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<vector<int>> result(n, vector<int>(k + 2, INT_MAX)); // Store min cost for each node with up to k stops

        // Build adjacency list
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            adj[u].emplace_back(v, w);
        }

        priority_queue<p, vector<p>, greater<p>> pq;  // Min-heap based on cost
        pq.push({0, src, 0});  // (cost, node, stops)
        result[src][0] = 0;  // No cost to reach source node with 0 stops

        while (!pq.empty()) {
            auto [wt, node, k2] = pq.top();  // Access tuple elements using structured binding
            pq.pop();

            // If the destination is reached, return the cost
            if (node == dst) return wt;

            // Explore neighbors if we can still make stops
            if (k2 <= k) {
                for (auto& [nextNode, nextWeight] : adj[node]) {
                    int newCost = wt + nextWeight;

                    // Only push to the queue if we found a cheaper way to reach nextNode with k2 + 1 stops
                    if (newCost < result[nextNode][k2 + 1]) {
                        result[nextNode][k2 + 1] = newCost;
                        pq.push({newCost, nextNode, k2 + 1});
                    }
                }
            }
        }

        // Find the minimum cost to reach dst with any number of stops up to k
        int minCost = INT_MAX;
        for (int i = 0; i <= k + 1; ++i) {
            minCost = min(minCost, result[dst][i]);
        }

        return minCost == INT_MAX ? -1 : minCost;  // Return -1 if no valid route found
    }
};
