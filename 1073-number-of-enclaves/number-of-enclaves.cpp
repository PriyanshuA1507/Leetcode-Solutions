class Solution {
public:
    using p = pair<int, int>;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<p> q;

        // Push all boundary cells with 1 into the queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = -1; // Mark as visited
                }
            }
        }

        // BFS traversal to mark all reachable '1's from the boundary
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            
            for(auto d : dir){
                int i = x + d[0];
                int j = y + d[1];

                if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = -1; // Mark as visited
                }
            }
        }

        // Count remaining '1's that are not reachable from boundaries
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
