class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> a;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        a.push_back(grid[i][j]);
        }
        }
        int size = n*m;
        k%=size;
        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());

        int l = 0;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        grid[i][j] = a[l];
        l++;
        }
        }

        return grid;
    
    }
};