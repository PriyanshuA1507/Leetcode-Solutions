class Solution {
public:
    bool checkbypatrite(vector<vector<int>>& graph,int i,int cc,vector<int>& color){
        color[i] = cc;
        for(auto v:graph[i]){
        if(color[v]==color[i]){
            return false;
        }
        if(color[v]==-1){
        int colorofv = 1 - cc;
        if(checkbypatrite(graph,v,colorofv,color)==false){
            return false;
        }
        }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
        if(color[i]==-1){
        if(checkbypatrite(graph,i,1,color)==false){
            return false;
        }
        }
        }
        return true;

    }
};