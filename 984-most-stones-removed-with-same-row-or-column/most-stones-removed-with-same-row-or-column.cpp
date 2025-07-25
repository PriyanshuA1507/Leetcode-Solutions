class Solution {
public:

   class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
      int countcomponents(int n) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (findUPar(i) == i) count++;
            }
            return count;
        }
};

    int removeStones(vector<vector<int>>& stones) {
       int n = stones.size();
       DisjointSet dsu(n);
       for(int i=0;i<n;i++){
      int row = stones[i][0], col = stones[i][1];
      for(int j=i+1;j<n;j++){
      int nr = stones[j][0], nc = stones[j][1];
      if(nr==row || nc == col){
       dsu.unionBySize(i,j);
      }
      }
       }
     int c = dsu.countcomponents(n);
     return n - c;
    }
};