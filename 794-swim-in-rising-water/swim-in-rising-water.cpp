class Solution {
public:
   using p = pair<int,pair<int,int>>;
   vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> vis(n,vector<bool>(n,false));
   
    int ans = -1e8;
   //  vector<vector<int>> ans(n,vector<int>(n,1e8));
     priority_queue<p,vector<p>,greater<p>> pq;
     pq.push({grid[0][0],{0,0}}); 
     vis[0][0] = true;
     while(pq.size()!=0){
     auto a = pq.top();
     int x = a.second.first;
     int y = a.second.second;
     int value = a.first;
     ans = max(ans,value);
     pq.pop();
     if(x==n-1 && y==n-1){
        return ans;
     }
     for(auto d:dir){
    int newx = x + d[0];
    int newy = y + d[1];
    if(newx>=0 && newy>=0 && newx<n && newy<n && !vis[newx][newy]){
    pq.push({grid[newx][newy],{newx,newy}});
    vis[newx][newy] = true;
    }
     }
     }
     return 1e8;
    }
};