class Solution {
public:
   bool check(vector<vector<int>>& adj,int curr,vector<int>& color,int cc){
  color[curr] = cc;
   for(int & v: adj[curr]){
if(color[v]==color[curr]){
    return false;
}
if(color[v]==-1){
int ccv = 1 - cc;
if(check(adj,v,color,ccv)==false){
    return false;
}
}
}
return true; 
}
    bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V,-1);
    for(int i=0;i<V;i++){
    if(color[i]==-1){
    if(check(graph,i,color,1)==false){
        return false;
    }
    }
    }
    return true;
    }
};