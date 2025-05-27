class Solution {
public:
    void dfs(vector<bool>& visited,int s,vector<vector<int>> rooms,int n){
     visited[s] = true;

     for(auto a:rooms[s]){
      if(!visited[a]){
       dfs(visited,a,rooms,n);
      }
     }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(visited,0,rooms,n);
    for(auto a:visited){
    if(a==false){
        return false;
    }
    }
    return true;

    }
};