class Solution {
public:
    using p = pair<int, int>;
   

    void dijkstra(vector<int>& distances, int src, unordered_map<int, vector<p>>& adj, int n) {
         priority_queue<p, vector<p>, greater<p>> pq;  
        distances[src] = 0;
        vector<bool> visited(n, false);
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto [currentDist, currentNode] = pq.top(); 
            pq.pop();
            
            if (visited[currentNode]) continue;  
            visited[currentNode] = true;
            
            for (auto& [neighbor, weight] : adj[currentNode]) {
                int newDist = currentDist + weight;
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<int> fromSrc(n, INT_MAX);  // Distance array from source
        vector<int> fromDest(n, INT_MAX);  // Distance array from destination
        
        unordered_map<int, vector<p>> adj;  // Adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w); 
        }

        dijkstra(fromSrc, 0, adj, n);  
        dijkstra(fromDest, n - 1, adj, n);  
         vector<bool> result(edges.size(),false);
        for(int i=0;i<edges.size();i++){
         long  u = edges[i][0];
         long  v = edges[i][1];
         long w = edges[i][2];
         if(fromSrc[u]+w+fromDest[v]==fromSrc[n-1]){
            result[i] = true;
         }
         else if(fromSrc[v]+w+fromDest[u]==fromSrc[n-1]){
            result[i] = true;
         }
        }
        return result;
    }
};
