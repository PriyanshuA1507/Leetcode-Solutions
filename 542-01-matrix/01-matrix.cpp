class Solution {
public:
   using p = pair<pair<int,int>,int>;
   vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     queue<p> q;
     vector<vector<int>> time(mat.size(),vector<int>(mat[0].size(),-1));
     for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[0].size();j++){
    if(mat[i][j]==0){
    q.push({{i,j},0});
    time[i][j] = 0;
    }
    }
     }
     while(q.size()!=0){
        int a = q.size();
    for(int i=0;i<a;i++){
    auto b = q.front();
    q.pop();
    for(auto d:dir){
    int i = b.first.first + d[0];
    int j = b.first.second + d[1];

    if(i>=0 && j>=0 && i<mat.size() && j<mat[0].size() && time[i][j]==-1){
     time[i][j] = b.second + 1;
    q.push({{i, j}, b.second + 1});
    }
    }
    }
     }
     return time;   
    }
};