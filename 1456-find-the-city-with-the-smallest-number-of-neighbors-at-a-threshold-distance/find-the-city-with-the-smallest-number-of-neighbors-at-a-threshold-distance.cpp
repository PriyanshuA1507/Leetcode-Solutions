class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        unordered_map<int,vector<pair<int,int>>> adj;

        // Building the adjacency list
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0]; 
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vector<int> mi(n, 0);

        // Run BFS or Dijkstra-like algorithm for each city
        for(int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.emplace(0, i);
            
            while(!pq.empty()){
                auto [d, node] = pq.top();
                pq.pop();
                
                if(d > dt) continue;
                
                for(auto& [nei, weight] : adj[node]){
                    int new_dist = d + weight;
                    if(new_dist <= dt && new_dist < dist[nei]){
                        dist[nei] = new_dist;
                        pq.emplace(new_dist, nei);
                    }
                }
            }

            // Count the number of reachable cities within the distance threshold
            for(int j = 0; j < n; j++){
                if(dist[j] <= dt) mi[i]++;
            }
        }

        // Find the city with the smallest number of reachable cities (and largest index in case of ties)
        int ans = -1;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(mi[i] <= mini) {
                mini = mi[i];
                ans = i;
            }
        }

        return ans;
    }
};
