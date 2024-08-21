class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        ////indegree
        int n = graph.size();
        int m = graph[0].size();
        vector<int> indegree(n,0);
       unordered_map<int,vector<int>> adj;
       for(int i=0;i<n;i++){
      for(int j=0;j<graph[i].size();j++){
        adj[graph[i][j]].push_back(i);
        indegree[i]++;
      }
      }
      queue<int> q;
      for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
      }
      vector<int> result;
    while(q.size()!=0){
     int a = q.front();
     q.pop();
     result.push_back(a);
     for(auto & b: adj[a]){
        indegree[b]--;
        if(indegree[b]==0){
            q.push(b);
        }
     }
    }
    sort(result.begin(),result.end());
    return result;
    }
};