class Solution {
public:
    using p = pair<double,int> ;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int src, int end) {
    unordered_map<int, vector<pair<int, double>>> adj;
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].emplace_back(edges[i][1], sp[i]);
            adj[edges[i][1]].emplace_back(edges[i][0], sp[i]);
        }
    vector<double> result(n,0);
    result[src] = 0;
    priority_queue<p> pq;
    pq.push({1,src});
    while(pq.size()!=0){
    int node =  pq.top().second;
    double p = pq.top().first;
    if(node == end){
        return p;
    }
    pq.pop();
    for(auto &vec: adj[node]){
    int nextnode = vec.first;
    double p2 = vec.second;
    double newp = p2*p;
    if(newp>result[nextnode]){
        result[nextnode] = newp;
        pq.push({newp,nextnode});
    }
    }
    }
    return result[end];
    }
};