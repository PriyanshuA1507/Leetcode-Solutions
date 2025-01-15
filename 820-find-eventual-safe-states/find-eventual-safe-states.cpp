class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        queue<int> q;
        vector<int> indegree(n,0);
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<graph.size();i++){
         for(auto a:graph[i]){
         adj[a].push_back(i);
         indegree[i]++;
         }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()!=0){
        auto a = q.front();
        ans.push_back(a);
        q.pop();
        for(auto v:adj[a]){
            indegree[v]--;
            if(indegree[v]==0){
            q.push(v);
            }
        }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};