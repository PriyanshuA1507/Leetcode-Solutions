class Solution {
public:
vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    bool iscycle(int si,int sj,vector<vector<char>>& grid,vector<vector<bool>>& visited,int pi,int pj){
        int m = grid.size(), n = grid[0].size();
        visited[si][sj] = true;
        for(auto d:dir){
        int newi = si + d[0];
        int newj = sj + d[1];

        if (newi>=0 && newi<m && newj>=0 && newj<n && grid[newi][newj] != grid[si][sj]) continue;

        if(newi>=0 && newi<m && newj>=0 && newj<n && visited[newi][newj] && (newi == pi && newj == pj)){
        continue;
        }
        else if(newi>=0 && newi<m && newj>=0 && newj<n && visited[newi][newj] && (newi != pi || newj != pj)){
        return true;
        }
        else if(newi>=0 && newi<m && newj>=0 && newj<n && !visited[newi][newj] && iscycle(newi,newj,grid,visited,si,sj)){
            return true;
        }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if(!visited[i][j] && iscycle(i,j,grid,visited,-1,-1)){
        return true;
        }
        }
        }
        return false;
    }
};