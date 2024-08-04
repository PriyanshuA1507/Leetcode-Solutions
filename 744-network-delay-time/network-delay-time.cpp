class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> m;
        for (auto &vec : times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            m[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (m.find(node) != m.end()) {
                for (auto &vec : m[node]) {
                    int adjnode = vec.first;
                    int dist = vec.second;
                    if (d + dist < result[adjnode]) {
                        result[adjnode] = d + dist;
                        pq.push({d + dist, adjnode});
                    }
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