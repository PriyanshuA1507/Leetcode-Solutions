class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                a.push_back(grid[i][j]);
            }
        }
        sort(a.begin(),a.end());
        int m = a[a.size()/2];
        int ans = 0;
        bool f = false;
        for(int i=0;i<a.size();i++){
            if(abs(a[i]-m)%x!=0){
                f = true;
                break;
            }
            else {
                ans += (abs(a[i]-m)/x);
            }
        }
        if(f){
            return -1;
        }
        return ans;
    }
};