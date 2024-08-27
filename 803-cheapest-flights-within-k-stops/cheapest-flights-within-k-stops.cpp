class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            adj[u].emplace_back(v, price);
        }

        // (node, cost, stops)
        queue<tuple<int, int, int>> q;
        q.emplace(src, 0, 0);

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        while (!q.empty()) {
            auto [node, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (const auto& [next, price] : adj[node]) {
                int newCost = cost + price;
                if (newCost < minCost[next] && stops <= k) {
                    minCost[next] = newCost;
                    q.emplace(next, newCost, stops + 1);
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
