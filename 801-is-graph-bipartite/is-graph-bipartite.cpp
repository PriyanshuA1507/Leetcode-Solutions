class Solution {
public:
    bool checkbipatrite(vector<vector<int>>& graph,int node,vector<int>& color,int currcolor){
    color[node]= currcolor;
    for(int v: graph[node]){
        if(color[v]==currcolor){
            return false;
        }
        if(color[v]==-1){
        int colorofv = 1-currcolor;
        if(checkbipatrite(graph,v,color,colorofv)==false)
            return false;
        }
    }
    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
    int v = graph.size();
      vector<int> color(v,-1);
      for(int i=0;i<v;i++){
    if(color[i]==-1){
        if(!checkbipatrite(graph,i,color,1)){
         return false;
        }
    }
      }
      return true;
    }
};