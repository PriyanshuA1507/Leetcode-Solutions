class Solution {
public:
  using p = pair<long long,pair<long long,long long>>;
   vector<vector<long long>> dir = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    long long shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    long long n = grid.size();
    priority_queue<p,vector<p>,greater<p>>q;
    vector<vector<long long>> result(n,vector<long long>(n,INT_MAX));
    result[0][0] = 0;
    q.push({0,{0,0}});
    while(q.size()!=0){
    auto a = q.top();
    q.pop();
    long long fd = a.first;
    long long fi = a.second.first;
    long long fj = a.second.second;
    for(auto d:dir){
    long long ni = fi + d[0];
    long long nj = fj + d[1];
    if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==0 && result[ni][nj]>fd+1){
     result[ni][nj] = fd+1;
     q.push({fd+1,{ni,nj}});
    }
    }
    }
    if(grid[0][0]==1 || grid[n-1][n-1]==1 || result[n-1][n-1]==INT_MAX){
        return -1;
    }
    return result[n-1][n-1]+1;
    }
};