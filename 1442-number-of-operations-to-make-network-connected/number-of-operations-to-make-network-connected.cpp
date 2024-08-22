class Solution {
public:
    int findparent(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = findparent(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = findparent(x, parent);
        int y_parent = findparent(y, parent);
        
        if (x_parent != y_parent) {
            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int redundant = 0;
        for (auto& a : connections) {
            if (findparent(a[0], parent) == findparent(a[1], parent)) {
                redundant++;
            } else {
                Union(a[0], a[1], parent, rank);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (findparent(i, parent) == i) {
                components++;
            }
        }

        if (redundant >= components - 1) {
            return components - 1;
        } else {
            return -1;
        }
    }
};
