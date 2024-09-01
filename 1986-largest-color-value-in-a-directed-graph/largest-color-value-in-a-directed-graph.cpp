class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<vector<int>> t(n, vector<int>(26, 0));
        int answer = 0;
        int edgecount = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            edgecount++;

            t[node][colors[node] - 'a']++;
            answer = max(answer, *max_element(t[node].begin(), t[node].end()));

            for (int& v : adj[node]) {
                for (int i = 0; i < 26; i++) {
                    t[v][i] = max(t[v][i], t[node][i]);
                }
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (edgecount < n) {
            return -1;  
        }

        return answer;
    }
};
