class Solution {
public:
  using p = pair<int,int>;
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
    
    int m = grid.size();
    int n = grid[0].size();

    queue<p>q;
    int fo=0;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
     if(grid[i][j]==2){
     q.push({i,j});
     }
     if(grid[i][j]==1){
     fo++;
     }
    }
    }
    if(fo==0){
        return 0;
    }
    int time = 0;
    while(q.size()!=0){
     int s = q.size();
     time++;
     for(int i=0;i<s;i++){
     auto p = q.front();
     q.pop();
     for(auto d:dir){
     int i = p.first + d[0];
     int j = p.second + d[1];
     if(i>=0 && j>=0 && i<m && j<n && grid[i][j]==1){
      grid[i][j]=2;
      fo--;
      q.push({i,j});
     }
     }
     }
    }
    if(fo==0){
        return time-1;
    }
    return -1;
    }
};