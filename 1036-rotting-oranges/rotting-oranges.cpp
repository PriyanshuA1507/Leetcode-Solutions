class Solution {
public:
 using p = pair<int,int>;
 vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int fo = 0;
        int ans =0;
        queue<p> q;
        for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
        if(grid[i][j]==1){
            fo++;
        }
        else{
            if(grid[i][j]==2){
            q.push({i,j});
            }
        }
        }
        }

     if(fo==0){
            return 0;
        }
        while(q.size()!=0){
        int c = q.size();
        for(int i=0;i<c;i++){
        auto a = q.front();
        q.pop();
        for(auto b:dir){
        int i = a.first + b[0];
        int j = a.second + b[1];
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1){
         q.push({i,j});
         grid[i][j]=2;
         fo--;
        }
        }
        }
        ans++;
        }
   if(fo!=0){
    return -1;
   }
  return ans-1;
    }
};