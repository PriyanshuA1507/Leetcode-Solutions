class Solution {
public:
   void dfs(int node, unordered_map<int, vector<int>>& copy, unordered_map<int, unordered_set<int>>& main, int& ans, vector<bool>& vis) {
    vis[node] = true;
    for (int a : copy[node]) {
        if (!vis[a]) {
           
            if (main[node].count(a)) {
                ans++;
            }
            dfs(a, copy, main, ans, vis);
        }
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
     unordered_map<int, vector<int>> copy;
    unordered_map<int, unordered_set<int>> main;
    vector<bool> vis(n, false);

    for (auto& a : connections) {
        int u = a[0];
        int v = a[1];
        main[u].insert(v);        
        copy[u].push_back(v);    
        copy[v].push_back(u);   
    }

    int ans = 0;
    dfs(0, copy, main, ans, vis);
    return ans;
    }
};