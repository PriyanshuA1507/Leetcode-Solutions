class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        if(n==1 && s==0 && d==0){
            return true;
        }
       unordered_map<int,vector<int>> adj;
       for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       vector<int> vis(n,false);
       queue<int> q;
       q.push(s);
       vis[s] = true;
       while(q.size()!=0){
        int size = q.size();
        for(int i=0;i<size;i++){
         auto a1 = q.front();
         q.pop();
         for(auto& ad: adj[a1]){
            if(ad==d){
                return true;
            }
            if(vis[ad]){
                continue;
            }
            vis[ad]=true;
            q.push(ad);
         }
        }
       }
       return false;
    }
};