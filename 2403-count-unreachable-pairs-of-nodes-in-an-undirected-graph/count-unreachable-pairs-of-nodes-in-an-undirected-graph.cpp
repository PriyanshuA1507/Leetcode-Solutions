class Solution {
public:
    int findparent(int x, vector<int>& parent) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findparent(parent[x], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = findparent(x, parent);
        int y_parent = findparent(y, parent);
        if (x_parent == y_parent) {
            return;
        }
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& a : edges) {
            Union(a[0], a[1], parent, rank);
        }

        
        vector<long long> component_size(n, 0);
        for (int i = 0; i < n; i++) {
            int root = findparent(i, parent);
            component_size[root]++;
        }

    
        long long ans = 0;
        long long total_pairs = (long long)n * (n - 1) / 2;
        for (int i = 0; i < n; i++) {
            if (component_size[i] > 0) {
                long long size = component_size[i];
                total_pairs -= size * (size - 1) / 2;
            }
        }

        return total_pairs;
    }
};
