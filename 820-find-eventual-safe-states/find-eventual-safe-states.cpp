class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     unordered_map<int,vector<int>> adj;
     vector<int> indegree(graph.size(),0);
     for(int i=0;i<graph.size();i++){
     for(auto a:graph[i]){
     adj[a].push_back(i);
     indegree[i]++;
     }
     }
     queue<int> q;
     for(int i=0;i<graph.size();i++){
     if(indegree[i]==0){
     q.push(i);
     }
     }
    vector<int> ans;
    while(q.size()!=0){
    int a = q.front();
    q.pop();
    ans.push_back(a);
    for(auto b:adj[a]){
        indegree[b]--;
        if(indegree[b]==0){
        q.push(b);
        }
    }
    }
    sort(ans.begin(),ans.end());
   return ans;
    }
};