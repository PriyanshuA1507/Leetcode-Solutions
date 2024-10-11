class Solution {
public:
    using p = pair<int,int>;
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<p> q;
        int fresh_oranges = 0;
        int minutes = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }
        if(fresh_oranges == 0) return 0;
        while(!q.empty()){
            int size = q.size();
            bool found_new_rotten = false; 
            for(int i = 0; i < size; i++) {
                auto a = q.front();
                q.pop();
                
                for(auto d : dir) {
                    int r = a.first + d[0];
                    int c = a.second + d[1];
                    
                    if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1) {
                        grid[r][c] = 2;  
                        q.push({r, c});
                        fresh_oranges--; 
                        found_new_rotten = true;
                    }
                }
            }
            
            if(found_new_rotten) minutes++;  
        }
        return fresh_oranges == 0 ? minutes : -1;
    }
};
