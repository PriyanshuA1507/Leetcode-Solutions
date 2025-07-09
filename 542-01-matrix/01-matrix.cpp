class Solution {
public:
 using p = pair<pair<int,int>,int>;
vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<p> q;
      int n = mat.size(), m = mat[0].size();
       vector<vector<int>> dist(n,vector<int>(m,1e8));
       unordered_map<int,vector<int>> adj;
       for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
      if(mat[i][j]==0){
    dist[i][j] = 0;
     q.push({{i,j},0});
      }
      }
       }

       while(q.size()!=0){
        auto s = q.size();
        for(int i=0;i<s;i++){
        auto a = q.front();
        q.pop();
        int row = a.first.first, col = a.first.second;
        int dista = a.second;
        for(auto d:dir){
        int nr = row + d[0];
        int nc = col + d[1];

        if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]==1){
        dist[nr][nc] = 1 + dista;
        mat[nr][nc] = 0;
        q.push({{nr,nc},dist[nr][nc]});
        }
        }
        }
       }
       return dist;
    }
};