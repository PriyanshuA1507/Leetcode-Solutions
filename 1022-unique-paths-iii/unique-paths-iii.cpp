class Solution {
public:
    int check(vector<vector<int>>& grid, int start, int end,int empty) {
        int n = grid.size();
        int m = grid[0].size();
        if (start >= n || end >= m || start < 0 || end < 0 || grid[start][end] == -1) {
            return 0;
        }
        if (grid[start][end] == 2) {
           return empty == -1 ? 1 : 0;
        }
        int temp = grid[start][end];
        grid[start][end] = -1;
        empty--;

        int found = check(grid, start + 1, end,empty) +
                     check(grid, start, end + 1,empty) +
                     check(grid, start - 1, end,empty) +
                     check(grid, start, end - 1,empty);

        grid[start][end] = temp;
        empty++;
        return found;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty=0;
        int s = 0;
        int e =0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    s = i;
                    e =j;
                    }
                    else if(grid[i][j]==0){
                        empty++;
                    }
                }
            }
        return check(grid,s,e,empty);
    }
};
