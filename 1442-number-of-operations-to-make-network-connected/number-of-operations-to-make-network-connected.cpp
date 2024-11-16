class Solution {
public:
    int findparent(int x,vector<int>& parent){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findparent(parent[x],parent);
    }
     void findunion(int x, int y, vector<int>& rank, vector<int>& parent) {
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
        if (connections.size() < n - 1) {
            return -1; 
        }
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int redundant = 0;
    for(auto& a:connections){
    if(findparent(a[0],parent)==findparent(a[1],parent)){
        redundant++;
    }
    else{
        findunion(a[0],a[1],rank,parent);
    }
    }
    int components = 0;
    for(int i=0;i<n;i++){
    if(findparent(i,parent)==i){
        components++;
    }
    }
    if(redundant>=components-1){
        return components-1;
    }
    else{
        return -1;
    }

    }
};