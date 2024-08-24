class Solution {
public:
   typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
    vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};
     vector<vector<int>> result(n,vector<int>(m,INT_MAX));
     priority_queue<p,vector<p>,greater<p>>pq;
     pq.push({0,{0,0}});
     result[0][0] = 0;
     while(pq.size()!=0){
    auto a = pq.top();
    pq.pop();
    int diff = a.first;
    int r = a.second.first;
    int c = a.second.second;
     if (r == n-1 && c == m-1) {
                return diff;  // Return the minimum effort when reaching the bottom-right corner
            }
    for(auto & d: direction){
     int nr = r + d[0];
     int nc = c + d[1];
     
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newEffort = max(diff, abs(h[r][c] - h[nr][nc]));
                    if (newEffort < result[nr][nc]) {
                        result[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
    }
     }
     return result[n-1][n-1];
    }
};