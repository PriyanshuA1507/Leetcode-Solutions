class Solution {
public:
    using p = pair<int,pair<int,int>>;
    int minCost(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
     vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
     priority_queue<p,vector<p>,greater<p>> pq;
     cost[0][0] = 0;
     pq.push({0,{0,0}});
     while(pq.size()!=0){
     auto a = pq.top();
     pq.pop();
     int cost1 = a.first;
     int x = a.second.first;
     int y = a.second.second;
     // first case
     if(grid[x][y]==1){
       if(y+1<m && cost[x][y+1]>cost1){
       cost[x][y+1] = cost1;
      pq.push({cost[x][y+1],{x,y+1}});
       }
       if(y-1>=0 && cost[x][y-1]>cost1+1){
        cost[x][y-1] = cost1+1;
      pq.push({cost[x][y-1],{x,y-1}});
       }
      if(x-1>=0 && cost[x-1][y]>cost1+1){
        cost[x-1][y] = cost1+1;
      pq.push({cost[x-1][y],{x-1,y}});
       }
        if(x+1<n && cost[x+1][y]>cost1+1){
        cost[x+1][y] = cost1+1;
      pq.push({cost[x+1][y],{x+1,y}});
       }
     }
  //second case
     if(grid[x][y]==2){
       if(y-1>=0 && cost[x][y-1]>cost1){
       cost[x][y-1] = cost1;
      pq.push({cost[x][y-1],{x,y-1}});
       }

       if(y+1<m && cost[x][y+1]>cost1+1){
        cost[x][y+1] = cost1+1;
      pq.push({cost[x][y+1],{x,y+1}});
       }
      if(x-1>=0 && cost[x-1][y]>cost1+1){
        cost[x-1][y] = cost1+1;
      pq.push({cost[x-1][y],{x-1,y}});
       }
        if(x+1<n && cost[x+1][y]>cost1+1){
        cost[x+1][y] = cost1+1;
      pq.push({cost[x+1][y],{x+1,y}});
       }
     }

     //case 3
     if(grid[x][y]==3){
       if(x+1<n && cost[x+1][y]>cost1){
       cost[x+1][y] = cost1;
      pq.push({cost[x+1][y],{x+1,y}});
       }

       if(y-1>=0 && cost[x][y-1]>cost1+1){
        cost[x][y-1] = cost1+1;
      pq.push({cost[x][y-1],{x,y-1}});
       }
      if(x-1>=0 && cost[x-1][y]>cost1+1){
        cost[x-1][y] = cost1+1;
      pq.push({cost[x-1][y],{x-1,y}});
       }
        if(y+1<m && cost[x][y+1]>cost1+1){
        cost[x][y+1] = cost1+1;
      pq.push({cost[x][y+1],{x,y+1}});
       }
     }

     //cost 4
     if(grid[x][y]==4){
       if(x-1>=0  && cost[x-1][y]>=0){
       cost[x-1][y] = cost1;
      pq.push({cost[x-1][y],{x-1,y}});
       }

       if(y-1>=0 && cost[x][y-1]>cost1+1){
        cost[x][y-1] = cost1+1;
      pq.push({cost[x][y-1],{x,y-1}});
       }
      if(y+1<m && cost[x][y+1]>cost1+1){
        cost[x][y+1] = cost1+1;
      pq.push({cost[x][y+1],{x,y+1}});
       }
        if(x+1<n && cost[x+1][y]>cost1+1){
        cost[x+1][y] = cost1+1;
      pq.push({cost[x+1][y],{x+1,y}});
       }
     }
     }
     return cost[n-1][m-1];
    }
};