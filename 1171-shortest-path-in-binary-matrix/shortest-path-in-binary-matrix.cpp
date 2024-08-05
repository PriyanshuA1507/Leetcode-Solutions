class Solution {
public:
  typedef pair<int,pair<int,int>> P;
   /* int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
          if (n == 0 || grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        queue<pair<int,int>> q;
       vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}, {-1,1}, {1,1}, {1,-1}, {-1,-1}};
        q.push({0,0});
        while(q.size()!=0){
        int size = q.size();
          ans++;
         while(size-->0){
         pair<int,int> a = q.front();
         q.pop();
         if (a.first == n-1 && a.second == n-1) return ans;
         for(auto & d: dir){
           int r = a.first + d[0];
           int c = a.second + d[1];
        if(r>=0 && c>=0 && r<n && c< n && grid[r][c]==0 && vis[r][c]==0){
            q.push({r,c});
            vis[r][c]=1;
        }
         }
        }
        }
         return -1;
    }*/
      int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}, {-1,1}, {1,1}, {1,-1}, {-1,-1}};
       int n = grid.size() ,m = grid[0].size();
       if(m==0 || n==0 || grid[0][0]!=0){
        return -1;
       }
       vector<vector<int>> result(m,vector<int>(n,INT_MAX));
       priority_queue<P, vector<P>, greater<P>> pq;
       pq.push({0,{0,0}});
       result[0][0]=0;
       while(!pq.empty()){
        int d = pq.top().first;
        pair<int,int> n1 = pq.top().second;
        int x = n1.first;
        int y = n1.second;
        pq.pop();
        for(auto dr: direction){
        int r = x + dr[0];
        int c = y + dr[1];
        int dist = 1;
        if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==0 && d+dist<result[r][c]){
        pq.push({d+dist,{r,c}});
        result[r][c] = d + dist;
        }
        }
       }
       if(result[m-1][n-1]==INT_MAX)
       return -1;

       return result[m-1][n-1]+1;
      }
};