class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
     unordered_map<int,vector<int>> adj;
     if(n==1){
        return {0};
     }
     vector<int> indegree(n,0);
     for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
         indegree[u]++;
         indegree[v]++;
             }   
     vector<int> result;
     queue<int> que;
     for(int i=0;i<n;i++){
        if(indegree[i]==1)
        que.push(i);
     }
     while(n>2){
     int size = que.size();
     n-=size;
     while(size-->0){
     int u = que.front();
     que.pop();
     for(int v:adj[u]){
        indegree[v]--;
        if(indegree[v]==1){
        que.push(v);
        }
     }
     }
     }
     while(!que.empty()){
        result.push_back(que.front());
        que.pop();
     }
    return result;
    }
};