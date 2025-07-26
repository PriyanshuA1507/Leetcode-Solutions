class Solution {
public:
class DisjointSet {
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1); 

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]); 
    }

    void unionbyrank(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionbysize(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv) return;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
     int countComponents(int n) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (parent[i] == i) count++;
            }
            return count;
        }
};
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }

        DisjointSet dsu(n);
        int ans = 0;
        for(auto a:connections){
         int u = a[0], v = a[1];
         dsu.unionbysize(u,v);
        }
        ans = dsu.countComponents(n);
        return ans-1;
    }
};