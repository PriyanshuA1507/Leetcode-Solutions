class Solution {
public:
   double dfs(string a,string b,unordered_map<string,vector<pair<string,double>>>& adj,unordered_set<string>& visited){
     if (a == b) return 1.0;
    visited.insert(a);
    for (auto& neighbor : adj[a]) {
            if (visited.find(neighbor.first) != visited.end()) continue; 
            
            double result = dfs(neighbor.first, b, adj, visited); 
            if (result != -1.0) {
                return result * neighbor.second;
            }
        }

        return -1.0;
   }
    vector<double> calcEquation(vector<vector<string>>& es, vector<double>& values, vector<vector<string>>& qs) {
        unordered_map<string,vector<pair<string,double>>>adj;
        int i=0;
        vector<double> ans;
        for (int i = 0; i < es.size(); i++) {
            adj[es[i][0]].emplace_back(es[i][1], values[i]);
            adj[es[i][1]].emplace_back(es[i][0], 1.0 / values[i]);
        }
        for(auto &a:qs){
            unordered_set<string> visited;
            if(adj.find(a[0])!=adj.end()){
         ans.push_back(dfs(a[0],a[1],adj,visited));}
         else {
                ans.push_back(-1.0); 
            }
        }
        return ans;
    }
};