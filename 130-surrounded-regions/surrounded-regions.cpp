class Solution {
public:
  void dfs(vector<vector<char>> &board,int i,int j,vector<vector<int>> &dir){
    board[i][j]='$';
    int n= board.size() , m= board[0].size();
    for(int d=0;d<dir.size();d++){
        int r = i+ dir[d][0];
        int c= j + dir[d][1];
    if(r>=0 && c>=0 && r<n && c<m && board[r][c]=='O'){
       
        dfs(board,r,c,dir);
    }

    }

  }
    void solve(vector<vector<char>>& board) {
       vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
       int n= board.size() , m= board[0].size();
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(i==0 || j==0 || i==n-1 || j==m-1){
                   if(board[i][j]=='O'){
                   dfs(board,i,j,dir);}
               }
           }
       }
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(board[i][j]=='$'){
                   board[i][j]='O';
               }
               else board[i][j]='X';
           }
       }

    }
};