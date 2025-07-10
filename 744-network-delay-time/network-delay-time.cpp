class Solution {
public:
using p = pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e8);
        unordered_map<int,vector<p>> adj;
        for(auto a:times){
        int u = a[0], v = a[1], w = a[2];
        adj[u].push_back({v,w});
        }
        priority_queue<p,vector<p>,greater<p>> q;
        dist[k] = 0;
        q.push({0,k});
        while(q.size()!=0){
        auto a = q.top();
        int d = a.first;
        q.pop();
        if(d>dist[a.second])continue;
        for(auto b:adj[a.second]){
        if(d+b.second<dist[b.first]){
        dist[b.first] = d+b.second;
        q.push({dist[b.first],b.first});
        }
        }
        }

        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e8) return -1; 
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};