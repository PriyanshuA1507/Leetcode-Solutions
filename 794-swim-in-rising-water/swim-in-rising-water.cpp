class Solution {
public:
    using p = pair<int, pair<int, int>>; 
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq; 
        pq.push({grid[0][0], {0, 0}});
        int ans = grid[0][0];
        
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        while (!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            ans = max(ans, a.first); 
            if (a.second.first == n - 1 && a.second.second == n - 1) {
                return ans;
            }
            
            for (auto d : dir) {
                int r = a.second.first + d[0];
                int c = a.second.second + d[1];
                if (r >= 0 && c >= 0 && r < n && c < n && vis[r][c] > max(grid[r][c], a.first)) {
                    vis[r][c] = max(grid[r][c], a.first);
                    pq.push({grid[r][c], {r, c}});
                }
            }
        }
        return 0; 
    }
};
