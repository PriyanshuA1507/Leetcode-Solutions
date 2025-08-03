#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer = 0;

    void dfs(unordered_map<int, vector<int>>& adj, int parent, int node,
             vector<int>& vis, vector<int>& disc, vector<int>& low,
             vector<vector<int>>& ans) {

        vis[node] = true;
        disc[node] = low[node] = timer++;

        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;

            if (!vis[nbr]) {
                dfs(adj, node, nbr, vis, disc, low, ans);
                low[node] = min(low[node], low[nbr]);

                if (low[nbr] > disc[node]) {
                    ans.push_back({min(node, nbr), max(node, nbr)});
                }
            } else {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> adj;

        for (auto a : connections) {
            int u = a[0], v = a[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> disc(n, -1);
        vector<int> low(n, -1);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, -1, i, vis, disc, low, ans);
            }
        }

        return ans;
    }
};
