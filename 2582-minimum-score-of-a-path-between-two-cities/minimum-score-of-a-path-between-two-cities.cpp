class Solution {
public:
    int minScore(int n, vector<vector<int>>& rd) {
      vector<vector<int>> adj[n+1];
        for(auto a : rd){
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        vector<int> vis(n+1,0);
        queue<vector<int>> pq;
        int ans =1e8;
        vis[1]=1;
        pq.push({1,100000});
        while(!pq.empty()){
            int ct = pq.front()[0]; pq.pop();
            for(auto a : adj[ct]){
                ans = min(ans,a[1]);
                if(!vis[a[0]]){
                    vis[a[0]]=1;
                    pq.push({a[0],a[1]});
                }
            }
        }
        return ans;  
    }
};