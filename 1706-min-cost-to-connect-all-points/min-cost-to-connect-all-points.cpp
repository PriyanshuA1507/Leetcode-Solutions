class Solution {
public:
  typedef pair<int,int> p;
    int mst(vector<vector<p>>& adj,int v){
    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push({0,0});
    vector<bool> inmst(v,false);

    int sum = 0;
    while(pq.size()!=0){
    auto p = pq.top();
    pq.pop();

    int wt = p.first;
    int node = p.second;
    if(inmst[node]){
        continue;
    }
    inmst[node] = true;
    sum+=wt;
    for(auto &tmp: adj[node]){
        int ni = tmp.first;
        int niw = tmp.second;

    if(inmst[ni]==false){
        pq.push({niw,ni});
    }
    }
    }
    return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
       int v = points.size();
       vector<vector<p>> adj(v);
       for(int i=0;i<v;i++){
    for(int j=i+1;j<v;j++){
     int x1 = points[i][0];
     int y1 = points[i][1];

    int x2 = points[j][0];
    int y2 = points[j][1];

    int d = abs(x1-x2)+ abs(y1-y2);
    adj[i].push_back({j,d});
    adj[j].push_back({i,d});
    }
    }
    return mst(adj,v);
        
    }
};