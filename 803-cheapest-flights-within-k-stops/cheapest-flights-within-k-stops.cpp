class Solution {
public:
    using p = pair<int,pair<int,int>>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int,vector<pair<int,int>>> adj;
    vector<vector<int>> ans(n,vector<int>(k+2,1e8));
    for(auto a:flights){
    int u = a[0];
    int v = a[1];
    int w = a[2];
    adj[u].push_back({v,w});
    }
    priority_queue<p,vector<p>,greater<p>> q;
    q.push({0,{src,0}});
    ans[src][0] = 0;
    while(q.size()!=0){
    auto a = q.top();
    q.pop();
    int distp = a.first;
    int k1 = a.second.second;
    int node = a.second.first;
    if(dst==node){
        return distp;
    }
    if(k1>k){
    continue;
    }
    for(auto b:adj[node]){
    if(distp+b.second<ans[b.first][k1+1]){
   ans[b.first][k1+1] = distp + b.second;
    q.push({ans[b.first][k1+1],{b.first,k1+1}});
    }
    }
    }
    return -1;
    }
};