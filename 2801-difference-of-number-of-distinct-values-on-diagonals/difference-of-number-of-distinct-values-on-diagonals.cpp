class Solution {
public:
   int solve(int i,int j,vector<vector<int>>& grid){
    set<int> lc;
    set<int> rc;
    int i1 = i,j1=j;
    while(i1>0 && j1>0){
        lc.insert(grid[i1-1][j1-1]);
        i1--;
        j1--;
    }
    i1 = i,j1 = j;
    while(i1<grid.size()-1 && j1<grid[0].size()-1){
        rc.insert(grid[i1+1][j1+1]);
        i1++;
        j1++;
    }
    int ans = abs(static_cast<int>(rc.size()) - static_cast<int>(lc.size()));
    return ans;
   }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            ans[i][j]= solve(i,j,grid);
        }
       } 
       return ans;
    }
};