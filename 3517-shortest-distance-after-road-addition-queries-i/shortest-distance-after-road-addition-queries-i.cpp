class Solution {
public:
    int bfs(unordered_map<int,vector<int>> adj,int start, int end){
       if (start == end) return 0; 
        queue<int> q;
        unordered_set<int> visited; 
        q.push(start);
        visited.insert(start);
        int distance = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            distance++;
            for (int i = 0; i < levelSize; i++) {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node]) {
                    if (neighbor == end) {
                        return distance; 
                    }
                    if (visited.find(neighbor) == visited.end()) { 
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }

        return -1; 
    }
 
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
     unordered_map<int,vector<int>> adj;
     vector<int> ans2;
     for(int i=0;i<n-1;i++){
     adj[i].push_back(i+1);
     }
     for(auto q:queries){
      int u = q[0];
      int v = q[1];
      adj[u].push_back(v);
      int ans = INT_MAX;
      ans = min(ans, bfs(adj,0,n-1));
      ans2.push_back(ans);
     }
    return ans2;
    }
};