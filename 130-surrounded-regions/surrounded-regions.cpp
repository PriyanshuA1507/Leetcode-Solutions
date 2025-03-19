class Solution {
public:
 vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
  using p = pair<int,int>;
    void solve(vector<vector<char>>& grid) {
           int m = grid.size(), n = grid[0].size();
    queue<p> q;
    for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[0].size();j++){
    if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 'O'){
                    q.push({i, j});
                    grid[i][j] = 'J';
      }
    }
    }
    
   while(!q.empty()){
            auto b = q.front();
            q.pop();
            int x = b.first, y = b.second; 
            
            for(auto d : dir){
                int ni = x + d[0];
                int nj = y + d[1];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 'O'){
                    q.push({ni, nj});
                    grid[ni][nj] = 'J'; 
                }
            }
        }

    for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'O') grid[i][j] = 'X';
                if(grid[i][j] == 'J') grid[i][j] = 'O';
            }
        }
           
    }
};