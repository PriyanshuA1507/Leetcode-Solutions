class Solution {
public:
   void dfs(int s,int e,vector<vector<int>>& graph,vector<int> a,vector<vector<int>>& ans){
     a.push_back(s);
     if(s==e){
        ans.push_back(a);
     }
     for(auto a1:graph[s]){
        dfs(a1,e,graph,a,ans);
     }
     a.pop_back();
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> a;
        dfs(0,n-1,graph,a,ans);
        return ans;
    }
};