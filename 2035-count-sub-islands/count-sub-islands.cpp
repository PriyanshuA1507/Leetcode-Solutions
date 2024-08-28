class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;  

    bool countsubislands_dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        grid2[i][j] = 0;
        bool res = true;
        for (vector<int> d : dir) {
            int r = i + d[0];
            int c = j + d[1];
            if (r >= 0 && c >= 0 && r < n && c < m && grid2[r][c] == 1) {
                res = countsubislands_dfs(grid1, grid2, r, c) && res;
            }
        }
        return res && (grid1[i][j] == 1);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();  
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    count += countsubislands_dfs(grid1, grid2, i, j) ? 1 : 0;
                }
            }
        }
        return count;
    }
};
