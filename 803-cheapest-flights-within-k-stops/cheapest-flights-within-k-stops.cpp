class Solution {
public:
  using p = pair<int,pair<int,int>>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      unordered_map<int, vector<pair<int, int>>> adj;
        
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<p, vector<p>, greater<p>> q;
        q.push({0, {src, 0}});
        
        // Track the minimum cost to reach each node with at most `k` stops
        vector<vector<int>> result(n, vector<int>(k + 2, INT_MAX));
        result[src][0] = 0;
        
        while (!q.empty()) {
            auto current = q.top();
            q.pop();
            
            int currCost = current.first;
            int node = current.second.first;
            int stops = current.second.second;
            
            // If we reached the destination, return the cost
            if (node == dst) return currCost;
            
            // If we have used up all stops, continue
            if (stops > k) continue;
            
            // Explore all the neighbors of the current node
            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int nextCost = neighbor.second;
                
                // If a cheaper path is found, push it to the queue
                if (currCost + nextCost < result[nextNode][stops + 1]) {
                    result[nextNode][stops + 1] = currCost + nextCost;
                    q.push({currCost + nextCost, {nextNode, stops + 1}});
                }
            }
        }
        
        // If we can't reach the destination
        return -1;
    }
};