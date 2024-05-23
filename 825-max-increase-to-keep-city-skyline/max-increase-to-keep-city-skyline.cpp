class Solution {
public:
    int check(vector<vector<int>>& grid, int row, int col, int ac) {
        int maxrow = INT_MIN;
        int maxcol = INT_MIN;
        
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[row][i] > maxrow) {
                maxrow = grid[row][i];
            }
        }
        
      
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][col] > maxcol) {
                maxcol = grid[i][col];
            }
        }
        int limit = min(maxrow, maxcol);
        return limit - ac;
    }
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans += check(grid, i, j, grid[i][j]);
            }
        }
        
        return ans;
    }
};
