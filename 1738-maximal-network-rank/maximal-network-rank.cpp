class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
     unordered_map<int, unordered_set<int>> adj;
        
        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];  
            adj[u].insert(v);
            adj[v].insert(u);
        }
      int ans = INT_MIN;
      for(int i=0;i<n;i++){
      int total = 0;
     for(int j=i+1;j<n;j++){
     int a = adj[i].size();
     int b = adj[j].size();
      total = a+b;
     if(adj[i].find(j)!=adj[i].end()){
        total-=1;
     }
       ans = max(ans,total);
    }
  }  
      return ans;
    }
};