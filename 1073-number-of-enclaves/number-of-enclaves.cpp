class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dir) {
        grid[i][j] = -1;
        int n = grid.size(), m = grid[0].size();
        for (int d = 0; d < dir.size(); d++) {
            int r = i + dir[d][0];
            int c = j + dir[d][1];
            if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1) {
                dfs(grid, r, c, dir);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        dfs(grid, i, j, dir);
                    }
                }
            }
        }
        int no = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    no++;
                }
            }
        }
        return no;
    }
};
