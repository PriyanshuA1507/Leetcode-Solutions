class Solution {
public:
   using p = pair<int,int>;
   vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<p>q;
        for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
         if(board[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)){
            q.push({i,j});
            board[i][j]='c';
         }
        }
        }
        while(q.size()!=0){
        int s = q.size();
        for(int i=0;i<s;i++){
        auto a = q.front();
        q.pop();
        for(auto d: dirs){
        int r = a.first + d[0];
        int c = a.second + d[1];

        if(r>=0 && c>=0 && r<n && c<m && board[r][c]=='O'){
            board[r][c] = 'c';
            q.push({r,c});
        }
        }
        }
        }
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        if(board[i][j]=='O' ){
            board[i][j]='X';
        }
        if (board[i][j] == 'c') {
                    board[i][j] = 'O'; 
                }
        }
        }
    }
};