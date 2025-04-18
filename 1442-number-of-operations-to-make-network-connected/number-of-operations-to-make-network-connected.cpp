class Solution {
public:
   void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
       stack<int> st;
       st.push(u);
       
       while (!st.empty()) {
           int node = st.top();
           st.pop();
           
           if (visited[node]) continue;
           visited[node] = true;

           for (int v : adj[node]) {
               if (!visited[v]) {
                   st.push(v);
               }
           }
       }
   }

   int makeConnected(int n, vector<vector<int>>& connections) {
       if (connections.size() < n - 1) {
           return -1;  
       }

     
       vector<vector<int>> adj(n);
       
       for (const auto& conn : connections) {
           int u = conn[0];
           int v = conn[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }

       vector<bool> visited(n, false);
       int count = 0;

       for (int i = 0; i < n; ++i) {
           if (!visited[i]) {
               count++;
               dfs(i, adj, visited);
           }
       }

       return count - 1;  
   }
};
