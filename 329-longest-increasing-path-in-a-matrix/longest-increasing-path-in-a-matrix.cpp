class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix.size() , m = matrix[0].size();
     vector<vector<int>> in(n,vector<int>(m,0));
     vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
     queue<int> q;
     for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
      for(vector<int>& d:dir){
         int r = i + d[0];
         int c = j + d[1];
    if(r>=0 && c>=0 && r<n && c<m && matrix[r][c]<matrix[i][j]){
         in[i][j]++;
    } 
      }
     if(in[i][j]==0){
    q.push(i*m+j);
     }
    }
   }
   int level = 0;
while(q.size()!=0){
    int size = q.size();
    while(size-->0){
     int idx = q.front();
     q.pop();
     int i = idx/m, j = idx%m;
     for(vector<int>& d:dir){
        int r = i + d[0];
        int c = j + d[1];
     if(r>=0 && c>=0 && r<n && c<m && matrix[r][c]>matrix[i][j] && --in[r][c]==0)
     q.push(r*m+c);
     }
    }
    level++;
}
return level;
}
};