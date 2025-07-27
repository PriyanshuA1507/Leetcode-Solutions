class Solution {
public:
    class DisjointSet {
    public:
        vector<int> rank, parent, size;

        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet dsu(n);
        unordered_map<string, int> mapmailnode;

        // Step 1: Map emails to account index and union if already seen
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapmailnode.find(mail) == mapmailnode.end()) {
                    mapmailnode[mail] = i;
                } else {
                    dsu.unionBySize(i, mapmailnode[mail]);
                }
            }
        }

        // Step 2: Group emails by parent
        vector<vector<string>> mergedmail(n);
        for (auto& it : mapmailnode) {
            string mail = it.first;
            int node = dsu.findUPar(it.second);
            mergedmail[node].push_back(mail);
        }

        // Step 3: Combine account name with merged emails
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedmail[i].empty()) continue;
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);  // Use the account name
            temp.insert(temp.end(), mergedmail[i].begin(), mergedmail[i].end());
            ans.push_back(temp);
        }

        return ans;
    }
};
