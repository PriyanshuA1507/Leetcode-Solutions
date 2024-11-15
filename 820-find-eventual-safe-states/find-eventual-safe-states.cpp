class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
    vector<int> result;
    queue<int> q;
    unordered_map<int,vector<int>> m;
     vector<int> indegree(n,0);   
     for(int i=0;i<n;i++){
        for(auto a: graph[i]){
            m[a].push_back(i);
            indegree[i]++;
        }
     }
     for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
     }
     while(q.size()!=0){
     int a = q.front();
     result.push_back(a);
     q.pop();
      for(auto b:m[a]){
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