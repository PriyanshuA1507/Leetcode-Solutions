class Solution {
public:
    int findParent(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findParent(parent, parent[x]);
    }

    void unionSets(int x, int z, vector<int>& parent) {
        int xParent = findParent(parent, x);
        int zParent = findParent(parent, z);
        if (xParent != zParent) {
            parent[xParent] = zParent;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (const auto& edge : edges) {
            unionSets(edge[0], edge[1], parent);
        }
        vector<long long> componentSize(n, 0);
        for (int i = 0; i < n; i++) {
            int root = findParent(parent, i);
            componentSize[root]++;
        }
        for (int i = 0; i < n; i++) {
            if (componentSize[i] > 0) {
                ans += componentSize[i] * (n - componentSize[i]);
            }
        }
        return ans / 2;
    }
};
