class Solution {
public:
    using p = pair<long long, int>; 

    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        
        vector<long long> result(n, LLONG_MAX);  
        result[0] = 0;

        
        vector<int> ways(n, 0);
        ways[0] = 1;

       
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});

        
        const int MOD = 1e9 + 7;

        while(!pq.empty()) {
            long long d = pq.top().first;  
            int node = pq.top().second;
            pq.pop();

          
            for(auto& v : adj[node]) {
                int neighbor = v.first;
                int d2 = v.second;

                if(d + d2 < result[neighbor]) {
                    result[neighbor] = d + d2;
                    ways[neighbor] = ways[node]; 
                    pq.push({result[neighbor], neighbor});
                } else if(d + d2 == result[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;  
                }
            }
        }

        return ways[n-1];  
    }
};