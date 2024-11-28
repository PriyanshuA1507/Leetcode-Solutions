class Solution {
public: 
  using p = pair<int,pair<int,int>>;
  vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
       int n = grid.size(), m = grid[0].size();
        vector<vector<int>> result(n, vector<int>(m, 1e9));
        result[0][0] = 0;
        priority_queue<p,vector<p>, greater<p>> pq;
        pq.push({0,{0,0}});
        while(pq.size()!=0){
         auto a = pq.top();
         pq.pop();
         if(a.second.first==n-1 && a.second.second==m-1){
            return result[n-1][m-1];
         }
         for(auto d: dir){
         int nr = a.second.first + d[0];
         int nc = a.second.second + d[1];
         
         if( nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && result[a.second.first][a.second.second]+1<result[nr][nc]){
            result[nr][nc] = result[a.second.first][a.second.second]+1;
            pq.push({result[nr][nc],{nr,nc}});
         }
         else if( nr>=0 && nc>=0 &&  nr<n && nc<m && grid[nr][nc]==0 && result[a.second.first][a.second.second]+0<result[nr][nc]){
            result[nr][nc] = result[a.second.first][a.second.second]+0;
            pq.push({result[nr][nc],{nr,nc}});
         }
         }
        }
        return -1;
    }
};