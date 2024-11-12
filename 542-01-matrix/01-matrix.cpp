class Solution {
public:
   vector<vector<int>> dirs = {{-1,0}, {0,1},{1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
         if(mat[i][j]==0){
            q.push({{i,j},0});
            vis[i][j] = 1;
         }
        }
        }
        while(q.size()!=0){
        auto a = q.front();
        int dist1 = a.second;
        dist[a.first.first][a.first.second] = a.second;
        q.pop();
        for(auto d:dirs){
         int row = a.first.first +d[0];
         int col = a.first.second +d[1];

         if(row>=0 && col>=0 && row<m && col<n && !vis[row][col]){
            vis[row][col] = 1;
            q.push({{row,col},dist1+1});
         }
        }
        }
       return dist;
    }
};