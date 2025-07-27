class Solution {
public:
  class DisjointSet {
public:
 vector<int> rank, parent, size;
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
};
 vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet dsu(n*n);
   
   //step 1

    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    if(grid[i][j]==1){
     for(auto d:dir){
    int newr = i +d[0];
    int newc = j + d[1];
    if(newr >=0 && newc >=0 && newr<n && newc<n && grid[newr][newc]==1){
     int nodeno = i*n + j;
     int adjnodeno = newr*n + newc;
     dsu.unionBySize(nodeno,adjnodeno);
    }
     }
    }
    }
    }
 //step 2
  int ans = 0;
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    set<int> components;
    if(grid[i][j]==0){
    for(auto d:dir){
     int newr = i + d[0];
     int newc = j + d[1];
     if(newr >=0 && newc >=0 && newr<n && newc<n && grid[newr][newc]==1){
     int nodeno = i*n + j;
     int adjnodeno = newr*n + newc;
     components.insert(dsu.findUPar(adjnodeno));
    }
    }
    }
    int size = 0;
    for(auto it: components){
    size += dsu.size[it];
    }
    ans = max(ans, size + 1);
    }
    }
   
   for(int i=0;i<n*n;i++){
   ans = max(ans,dsu.size[dsu.findUPar(i)]);
   }
   return ans;
    }
};