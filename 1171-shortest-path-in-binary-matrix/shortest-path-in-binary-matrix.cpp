class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {-1,-1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,1}};
    
   /* int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        
        int pathLength = 1; // Start from the first cell
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                if (r == n-1 && c == n-1) {
                    return pathLength;
                }
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && !visited[nr][nc]) {
                        q.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
            ++pathLength;
        }
        
        return -1; // If we reach here, there's no path
    }*/
    typedef pair<int,pair<int,int>> pp;
     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
    priority_queue<pp ,vector<pp>, greater<pp>>pq;
    vector<vector<int>> result(n+1,vector<int>(n+1,INT_MAX));
    result[0][0]=0;
    pq.push({0,{0,0}});
    while(pq.size()!=0){
     auto a = pq.top();
     pq.pop();
     pair<int,int>p = a.second;
     int dist = a.first;
     for(auto b: dirs){
     int nr = p.first + b[0];
     int nc = p.second + b[1];
     int dist1 = 1;
  if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && result[nr][nc]>dist1+dist) {
                   pq.push({dist+dist1,{nr, nc}});
               result[nr][nc]=dist1+dist;
        }
     }
    }
  if(result[n-1][n-1]==INT_MAX){
    return -1;
  }
  return result[n-1][n-1]+1;
     }
};
