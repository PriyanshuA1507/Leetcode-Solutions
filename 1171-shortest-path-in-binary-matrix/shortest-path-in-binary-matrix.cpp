class Solution {
public:
    using p = pair<int,int>;
    vector<vector<int>> dirs = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    queue<p> q;
    q.push({0,0});
    int pathlength=1;
    visited[0][0] = true;
    while(q.size()!=0){
    int size = q.size();
    for(int i=0;i<size;i++){
    auto a = q.front();
    int j = a.first;
    int k = a.second;
    q.pop();
    if(j==n-1 && k==n-1){
        return pathlength;
    }
    for(auto d:dirs){
    int r = j + d[0];
    int c = k + d[1];
    if(r>=0 && c>=0 && r<n && c<n && !visited[r][c] && grid[r][c]==0){
        visited[r][c] = true;
        q.push({r,c});
    }
    }
    }
    pathlength++;
    }
     return -1;
    }
};