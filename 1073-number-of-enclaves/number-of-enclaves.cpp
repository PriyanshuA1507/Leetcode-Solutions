class Solution {
public:
     using p = pair<int,int>;
     vector<vector<int>> dirs = {{-1,0}, {0,1},{1,0},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        queue<p> q;
        int c =0;
        int n = grid.size() ,m = grid[0].size();
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        if(grid[i][j]==1 &&(i==0 || j==0 || i==n-1 || j==m-1)){
            q.push({i,j});
            grid[i][j]=-1;
        }
        }
        }
        while(q.size()!=0){
            int size = q.size();
            for(int i=0;i<size;i++){
            auto a = q.front();
            q.pop();

            for(auto d: dirs){
            int r = a.first + d[0];
            int c = a.second + d[1];

            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1){
            grid[r][c] = -1;
            q.push({r,c});
            }
            }
            }
        }
            for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]==-1){
                grid[i][j] = 1;
            }
            else if(grid[i][j]==1){
                c++;
            }
            }
            }
            return c;

    }
};