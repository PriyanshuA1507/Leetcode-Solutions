class Solution {
public:
  using p = pair<int,int>;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        
        priority_queue<p, vector<p> ,greater<p>> pq;
        for(int i=0;i<n;i++){
            pq.push({indegree[i],i});
        }
       vector<int> cost(n,0);
       int i=1;
       while(pq.size()!=0){
        auto a = pq.top();
        pq.pop();
        cost[a.second] = i++;
       }
      long long ans = 0;
      for(auto a: roads){
        ans +=cost[a[0]];
        ans +=cost[a[1]];
      }
      return ans;
        
    }
};